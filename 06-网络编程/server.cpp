#include<iostream>
#include<sys/socket.h>      // socket/bind/listen/accept/recv/send 套接字函数
#include<netinet/in.h>      // sockaddr_in 地址结构体
#include<arpa/inet.h>       // inet_ntoa/htonl/htons 地址与字节序转换
#include<unistd.h>          // close 关闭套接字
#include<cstring>           // memset
using namespace std;
// int main(){
//     // ============ 第一步：socket() 拿总机 ============
//     // AF_INET: IPv4；SOCK_STREAM: TCP流式传输(打电话)；0: 让系统自动选协议
//     // SOCK_DGRAM 就是 UDP(发短信)
//     int fd=socket(AF_INET,SOCK_STREAM,0);
//     // fd=文件描述符(总机的编号)；成功返回非负整数，失败返回-1

//     // ============ 第二步：bind() 装SIM卡定号码 ============
//     struct sockaddr_in addr;                // 地址申请表：装"自己家"的IP+端口
//     memset(&addr,0,sizeof(addr));           // 先清空残留垃圾值
//     addr.sin_family=AF_INET;                // IPv4 家庭
//     addr.sin_addr.s_addr=htonl(INADDR_ANY); // 本机任意IP(0.0.0.0)，不管客户端连哪个网卡都接
//                                             // htonl=主机字节序转网络字节序(32位长整数,给IP用)
//     addr.sin_port=htons(8888);              // 端口号8888；htons=主机转网络(16位短整数,给端口用)
//     if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
//         perror("bind error");               // 失败打印错误原因
//         return -1;
//     }
//     // (struct sockaddr*)&addr 是类型强转，bind 老接口用旧类型，照抄即可

//     // ============ 第三步：listen() 开机待机 ============
//     if(listen(fd,5)==-1){                   // 5=待接队列长度，最多5个客户端排队等接通
//         perror("listen error");
//         return -1;
//     }
//     // 从这刻起内核开始维护队列，三次握手在内核自动完成，代码看不到

//     // ============ 第四步：accept() 接电话 ============
//     struct sockaddr_in client_addr;         // 空盒子：让系统填"来电者"的地址(IP+端口)
//     socklen_t len=sizeof(client_addr);
//     int client_fd=accept(fd,(struct sockaddr*)&client_addr,&len);
//     // 会【阻塞】——卡住等到有客户端连进来才返回
//     // 返回 client_fd=专属线路，只和这一个客户端通话；
//     // 原来的 fd=总机，继续监听新来电。两者完全不同！

//     cout<<"client fd:"<<client_fd<<endl;

//     // ============ 第五步：recv()/send() 通话 ============
//     char buff[1024];    
//                                    // 递话筒：准备一块内存装收到的数据
//     while(true){
//         int n=recv(client_fd,buff,sizeof(buff),0);         // 听：读客户端发来的数据放进 buff
//         // 阻塞等消息；返回值 n 有三种情况：
//         //   n>0    → 收到数据，n=实际字节数
//         //   n==0   → 对方挂断了（客户端 close 了）
//         //   n==-1  → 出错
//         if(n<=0)break;                                        // n<=0 就跳出循环，结束通话

//     send(client_fd,buff,n,0);                          // 说：把刚收到的 n 个字节原样弹回去
//     // echo(回声)=你说啥我回啥；buf=要发的内容，n=发几个字节，0=默认方式
//     }
//     close(client_fd);          // 挂电话：关闭这条专属线路
//     close(fd);                 // 关总机：不再接任何电话
//     cout<<"socket fd:"<<fd<<endl;
//     return 0;
// }
int main(){
    // ============ 第一步：socket() 拿总机 ============
    int fd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;//IPV4
    addr.sin_addr.s_addr=htonl(INADDR_ANY);//本机任意IP
    addr.sin_port=htons(8888);//端口号8888
    int opt=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));//设置端口复用
    // ============ 第二步：bind() 装SIM卡定号码 ============
    if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("bind error");
        return -1;
    }

    // ============ 第三步：listen() 开机待机 ============
    if(listen(fd,5)==-1){
        perror("listen error");
        return -1;
    }

    // ============ 第四步：accept() 接电话 ============
    struct sockaddr_in client_addr;
    socklen_t len=sizeof(client_addr);
    int client_fd=accept(fd,(struct sockaddr*)&client_addr,&len);
     
    // ============ 第五步：recv()/send() 通话 ============
    char buf[1024];
    while(true){
        int n=recv(client_fd,buf,sizeof(buf),0);
        if(n<=0)break;
        cout<<"一次recv收到"<<n<<"字节"<<endl;
        cout<<"内容:"<<buf<<endl;
        send(client_fd,buf,n,0);
    }
    
    // ============ 第六步：close() 挂电话 ============
    close(client_fd);
    close(fd);
}