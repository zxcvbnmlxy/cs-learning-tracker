#include<iostream>
#include<sys/socket.h>
// #include<thread>
#include<sys/epoll.h>
#include<netinet/in.h>
#include<arpa/inet.h>
// #include<mutex>
#include<cstring>
#include<unistd.h>
#include<fcntl.h>
#include<cerrno>
using namespace std;
int main(){

    int fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY);
    addr.sin_port=htons(8888);
    int opt=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));//端口复用，不用等待MSL时间也就是服务端断掉连接之后还要等待MSL*2时间才能使用端口
    if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("bind error");
        return -1;
    }
    if(listen(fd,5)<0){
        perror("listen error");return 0;
    }
    
    int epfd=epoll_create(1);
    struct epoll_event ev;
    ev.data.fd=fd;
    ev.events=EPOLLIN;
    epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev);
    struct epoll_event events[128];
    while(true){
        int n=epoll_wait(epfd,events,128,-1);
        for(int i=0;i<n;i++){
            if(events[i].data.fd==fd){
                struct sockaddr_in client_addr;
                socklen_t len=sizeof(client_addr);
                int client_fd=accept(fd,(struct sockaddr*)&client_addr,&len);
                fcntl(client_fd,F_SETFL,fcntl(client_fd,F_GETFL)|O_NONBLOCK);
                ev.data.fd=client_fd;
                ev.events=EPOLLIN|EPOLLET;
                epoll_ctl(epfd,EPOLL_CTL_ADD,client_fd,&ev);
            }
            else {
                struct sockaddr_in client_addr;
                int client_fd=events[i].data.fd;
                char buff[1024];
                while(true){
                int n=recv(client_fd,buff,sizeof(buff),0);
                if(n<0){
                    if(errno==EAGAIN)break;
                    epoll_ctl(epfd,EPOLL_CTL_DEL,client_fd,&ev);
                    close(client_fd);
                    break;
                }
                if(n==0){
                 epoll_ctl(epfd,EPOLL_CTL_DEL,client_fd,&ev);
                 close(client_fd);  
                 break;
                }
                send(client_fd,buff,n,0);
                }
            }
        }

    }
    return 0;
}