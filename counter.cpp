#include<iostream>
#include<thread>
#include<atomic>
using namespace std;

atomic<int> cnt(0); // 计数器，初始值为0

// long long cnt=0;
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