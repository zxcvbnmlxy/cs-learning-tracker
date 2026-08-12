#include<thread>
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<cstring>
#include<mutex>
using namespace std;

mutex mtx; // 互斥锁，保护共享资源
// 线程函数：专门和某个客户端通话
void handle_client(int client_fd){
    char buff[1024];
    while(true){
        int n=recv(client_fd,buff,sizeof(buff),0);

        if(n<=0)break;// n<=0 就跳出循环，结束通话 // 阻塞等消息；返回值 n 有三种情况： //   n>0    → 收到数据，n=实际字节数
        //   n==0   → 对方挂断了（客户端 close 了）//   n==-1  → 出错
        mtx.lock(); // 上锁，保护共享资源
        cout<<"recv:"<<n<<endl;
        cout<<"recv:"<<buff<<endl;
        mtx.unlock(); //解锁
        send(client_fd,buff,n,0); // echo(回声)=你说啥我回啥；buf=要发的内容，n=发几个字节，0=默认方式
       
    }
    close(client_fd); // 挂电话：关闭这条专属线路
}
int main(){
    // ============ 第一步：socket() 拿总机 ============
    int fd=socket(AF_INET,SOCK_STREAM,0);

    // ============ 第二步：bind() 装SIM卡定号码 ============
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=htonl(INADDR_ANY);
    addr.sin_port=htons(8888);
    int opt=1;
    setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt)); // 端口复用，防止程序异常退出后端口被占用
    if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))==-1){
        perror("bind error");return -1;
    }

    // ============ 第三步：listen() 开机待机 ============
    if(listen(fd,5)==-1){  // 5=待接队列长度，最多5个客户端排队等接通
        perror("listen error");return -1;
    }

    // ============ 第四步：accept() 接电话 ============
    while(true){
        struct sockaddr_in client_addr;
        socklen_t len=sizeof(client_addr);
        int client_fd=accept(fd,(struct sockaddr*)&client_addr,&len);
        cout<<"client_fd="<<client_fd<<endl;
        if(client_fd==-1){
            perror("accept error");continue;
        }
        thread t(handle_client,client_fd); // 创建线程，专门和这个客户端通话
        t.detach(); // 线程分离，线程结束后自动释放资源
    }

}