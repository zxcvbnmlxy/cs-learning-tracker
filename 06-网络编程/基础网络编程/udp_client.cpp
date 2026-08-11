#include<iostream>
#include<sys/socket.h>      // socket/connect/send/recv
#include<netinet/in.h>      // sockaddr_in  
#include<arpa/inet.h>       // inet_addr
#include<unistd.h>          // close        
#include<cstring>
using namespace std;
int main(){
    // ============ 第一步：socket() 拿手机 ============
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0)    {perror("socket error");return -1;}
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(8888);
    // ============ 第二步：通话 sendto()/recvfrom() ============
    char buff[3000];
    while(true){
        cin.getline(buff,sizeof(buff));
        if(strlen(buff)==0)break;
        sendto(fd,buff,strlen(buff),0,(struct sockaddr*)&addr,sizeof(addr));
        int n=recvfrom(fd,buff,sizeof(buff),0,nullptr,nullptr);
        if(n<=0)break;// 服务器挂了就退出
        buff[n]='\0';
        cout<<"服务器回声:"<<buff<<endl;
    }
    close(fd);
    return 0;
}