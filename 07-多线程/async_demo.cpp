#include<iostream>
#include<future>
#include<thread>
#include<chrono>
using namespace std;

//<future>全家桶

// future          = 取餐号（结果容器，只能取一次）
// async           = 一键下单（系统自动开线程 + 自动填结果）  
// promise         = 手动填结果（你亲自把菜放进取餐柜）  访问跨线程变量
// packaged_task   = 打包好的活儿（函数 + future 一体，自己决定谁来做）


// promise 骨架（注意那个 move）

// std::promise<int> p;                 // 后厨
// std::future<int> f = p.get_future(); // 提前拿取餐号

// std::thread t([](std::promise<int> pr){
//     // ……算……
//     pr.set_value(25);                // 手动把结果塞进后厨 → future 就绪
// }, std::move(p));                    // ← promise 不可拷贝，必须 move

// std::cout << f.get() << "\n";        // 25
// t.join();


//packaged_task骨架

// std::packaged_task<int(int)> task(calc);   // 函数+future 打包
// auto f = task.get_future();                  // 调用前先拿号

// std::thread t(std::move(task), 6);           // 把活儿交给一个线程跑
// std::cout << f.get() << "\n";                // 36
// t.join();
int calc(int x){
    this_thread::sleep_for(chrono::seconds(2));
    return x*x;
}
int main(){
    future<int> f=async(launch::async,calc,5);
    for(int i=0;i<5;i++){
        cout<<"休息300毫秒"<<endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    int result=f.get();

    cout<<result<<endl;

    cout<<f.get()<<endl;//future_error No associated state get()不能调用两次
    return 0;
}