#include <thread>        // 线程库：std::thread，创建和管理线程
#include <iostream>      // 标准输入输出流
#include <sys/socket.h>  // 套接字接口：socket / bind / listen / accept / send / recv
#include <netinet/in.h>  // sockaddr_in 结构体、AF_INET 地址族、htons / htonl
#include <arpa/inet.h>   // IP 地址转换相关函数
#include <unistd.h>      // POSIX 系统调用：close
#include <cstring>       // memset、strlen 等内存操作
#include <mutex>         // 互斥量：std::mutex
using namespace std;

// 全局互斥量 mtx
// 保护对象：标准输出 cout（共享资源）
// 作用：多线程并发写 cout 会交错，加锁保证一次只有一个线程输出
mutex mtx;

// 线程函数 handle_client
// 职责：处理单个客户端的连接，负责收发数据（本实现为回声 echo）
// 参数 client_fd：已连接套接字的文件描述符（accept 的返回值）
// 说明：每个客户端连接由一个独立线程执行本函数
void handle_client(int client_fd) {
    // 应用层接收缓冲区 buff
    // 作用：暂存从内核接收缓冲拷贝出来的数据
    char buff[1024];

    // 事件循环：阻塞式读取对端数据，直到连接断开
    while (true) {
        // recv() 系统调用：从内核接收缓冲读数据到应用缓冲区
        // 返回值 n 有三种情况：
        //   n > 0   → 实际接收到的字节数
        //   n == 0  → 对端已关闭连接（收到 FIN，读到 EOF）
        //   n == -1 → 出错（具体原因看 errno）
        int n = recv(client_fd, buff, sizeof(buff), 0);

        // 连接已结束：退出事件循环（对端 close 或出错）
        if (n <= 0)
            break;

        // 加锁：串行化对 cout 的访问，防止多线程输出交错
        mtx.lock();
        cout << "recv:" << n << endl;
        cout << "recv:" << buff << endl;
        mtx.unlock(); // 解锁

        // send() 系统调用：把刚收到的数据原样写回对端（回显）
        // 参数依次：已连接套接字 fd / 发送缓冲区 / 发送字节数 / flags(0 = 默认)
        send(client_fd, buff, n, 0);
    }

    // close()：关闭已连接套接字
    // 效果：释放文件描述符，并触发四次挥手（本端成为主动关闭方）
    close(client_fd);
}

// 主函数 main：服务器主控流程（监听 → 接受 → 派线程）
int main() {
    // ============ 第一步：socket() 创建套接字 ============
    // socket()：向内核申请一个套接字对象，返回其文件描述符 fd
    //   AF_INET      → IPv4 地址族
    //   SOCK_STREAM  → 流式套接字（面向字节流，对应 TCP）
    //   0            → 协议自动选择（TCP）
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // ============ 第二步：bind() 绑定本地地址 ============
    // sockaddr_in 结构体 addr：IPv4 套接字地址（含 IP 和端口）
    struct sockaddr_in addr;

    // memset：将结构体清零，避免未初始化残留数据
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;               // 地址族：IPv4
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // 监听本机所有网卡 IP（0.0.0.0）
    addr.sin_port = htons(8888);             // 端口号：主机字节序 → 网络字节序

    // setsockopt()：设置套接字选项
    // SO_REUSEADDR：地址复用，防止服务器退出后 TIME_WAIT 占用端口导致重启 bind 失败
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // bind()：把本地地址（IP + 端口）绑定到套接字
    // 成功返回 0，失败返回 -1
    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind error");
        return -1;
    }

    // ============ 第三步：listen() 进入监听状态 ============
    // listen()：将套接字从主动连接转为被动监听，内核维护待连接队列
    // 第二个参数 5：待连接队列（backlog）的最大长度
    if (listen(fd, 5) == -1) {
        perror("listen error");
        return -1;
    }

    // ============ 第四步：accept() 接受连接 ============
    // 循环：每接受一个客户端连接，就创建一个新线程处理
    while (true) {
        // client_addr：记录对端（客户端）的地址信息，由 accept 填充
        struct sockaddr_in client_addr;

        // len：地址结构体长度
        // 必须初始化为 sizeof，accept 会把它当作输入输出参数
        socklen_t len = sizeof(client_addr);

        // accept()：从待连接队列取出一个已建立连接的客户端
        // 返回一个新分配的文件描述符 client_fd（区别于监听 fd）
        // 成功返回新的已连接套接字 fd，失败返回 -1
        int client_fd = accept(fd, (struct sockaddr *)&client_addr, &len);

        cout << "client_fd=" << client_fd << endl;

        // accept 失败：本次连接放弃，continue 继续接受下一个
        if (client_fd == -1) {
            perror("accept error");
            continue;
        }

        // 创建线程 t：把 client_fd 交给线程，专门处理这个连接
        thread t(handle_client, client_fd);

        // detach()：线程分离，线程运行结束后自动回收资源
        // 主线程不 join 等待，可以立即继续 accept 下一个连接
        t.detach();
    }
}
