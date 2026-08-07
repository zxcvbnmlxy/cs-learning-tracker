#include<iostream>
#include<sys/socket.h>      // socket/connect/send/recv
#include<netinet/in.h>      // sockaddr_in  
#include<arpa/inet.h>
#include<unistd.h>          // close
#include<cstring>           // memset/strlen
using namespace std;
int main(){
    // ============ 第一步：socket() 拿总机============
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0){perror("socket error");return -1;}
    // ============ 第二步：bind() 装SIM卡定号码 ============
    struct  sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY);// 本机任意IP32位
    addr.sin_port=htons(8888);// 服务器端口16位
    if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("bind error");
        return -1;
    }
    // ============ 第三步：recvfrom()/sendto() 通话 ============
    struct sockaddr_in client_addr;
    socklen_t len=sizeof(client_addr);
    char buf[1024];
    while(true){
        int n=recvfrom(fd,buf,sizeof(buf),0,(struct sockaddr*)&client_addr,&len);
        if(n<=0)break;
        cout<<"收到客户端:"<<buf<<endl;
        sendto(fd,buf,n,0,(struct sockaddr*)&client_addr,len);
    }
    close(fd);  

    return 0;
}