#include<iostream>
#include<sys/socket.h>      // socket/connect/send/recv
#include<netinet/in.h>      // sockaddr_in
#include<arpa/inet.h>       // inet_addr
#include<unistd.h>          // close
#include<cstring>           // memset/strlen
using namespace std;
// int main(){
//     // ============ 第一步：socket() 拿手机 ============
//     int fd=socket(AF_INET,SOCK_STREAM,0);   // 和 server 一模一样
//     if(fd<0){perror("socket error");return -1;}

//     // ============ 第二步：connect() 拨号 ============
//     // ⚠️ 新知识点：填的是【对方(服务器)】的地址，不是自己的！
//     // 对比 server 的 bind：bind 填自己家(INADDR_ANY)，connect 填对方家(具体IP)
//     struct sockaddr_in addr;
//     memset(&addr,0,sizeof(addr));
//     addr.sin_family=AF_INET;                      // IPv4
//     addr.sin_addr.s_addr=inet_addr("127.0.0.1");  // 服务器IP（本机测试用回环地址）
//     addr.sin_port=htons(8888);                    // 服务器端口
//     if(connect(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
//         perror("connect error");
//         return -1;
//     }
//     cout<<"连接成功！和服务器接上线了"<<endl;

//     // ============ 第三步：通话 recv/send ============
//     char buf[1024];
//     while(true){
//         cout<<"你说:";
//         cin.getline(buf,sizeof(buf));     // ① 读键盘：你在终端打的字进 buf
//         if(strlen(buf)==0)break;          // 直接回车 = 结束聊天

//         send(fd,buf,strlen(buf),0);       // ② 说：把 buf 发给服务器

//         int n=recv(fd,buf,sizeof(buf),0); // ③ 听：等服务器回声
//         if(n<=0)break;                    // 服务器挂了就退出
//         buf[n]='\0';                      // 补结束符，好当字符串打印
//         cout<<"服务器回声:"<<buf<<endl;   // ④ 显示服务器弹回来的话
//     }
//     close(fd);                            // 挂机
//     cout<<"通话结束，挂了。"<<endl;
//     return 0;
// }
int main(){
    // ============ 第一步：socket() 拿手机 ============
    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd<0){perror("socket error");return -1;}
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;// IPv4
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr.sin_port=htons(8888);// 服务器端口
    
    // ============ 第二步：connect() 拨号 ============
    if(connect(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("connect error");
        return -1;
    }

    cout<<"连接成功！和服务器接上线了"<<endl;
    // ============ 第三步：通话 recv/send ============
    char buff[1024];
    while(true){
        cin.getline(buff,sizeof(buff));// ① 读键盘：你在终端打的字进 buf
        if(strlen(buff)==0)break;// 直接回车 = 结束聊天
        send(fd,buff,strlen(buff),0);// ② 说：把 buf 发给服务器
        int n=recv(fd,buff,sizeof(buff),0);// 等服务器回声
        if(n<=0)break;// 服务器挂了就退出
        buff[n]='\0';// 补结束符，好当字符串打印
        cout<<"服务器回声:"<<buff<<endl;// 显示服务器弹回来的话
    }
    close(fd);// 挂机
    cout<<"通话结束，挂了。"<<endl;
    return 0;
}