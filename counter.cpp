#include<iostream>
#include<thread>
using namespace std;

long long cnt=0; // 共享资源：计数器

void work(){// 线程函数：对计数器进行加法操作
    for(int i=0;i<10000000;i++){
        cnt++; // cnt=cnt+1; // 读-改-写
    }
}
int main(){
    thread t1(work); // 创建线程1
    thread t2(work); // 创建线程2
    t1.join(); // 等待线程1结束
    t2.join(); // 等待线程2结束
    cout<<"cnt="<<cnt<<endl; // 输出计数器的值
}