#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<chrono>
std::mutex mtx;
std::condition_variable cv;//条件变量，满足条件在执行
bool ready=false;

void producer(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::unique_lock<std::mutex> lk(mtx);
        ready=true;
        cv.notify_one();
        std::cout<<"通知完毕！"<<std::endl;
    }
    // std::this_thread::sleep_for(std::chrono::milliseconds(200));
    // {
    //     std::unique_lock<std::mutex> lk(mtx);
    //     ready=true;
    //     std::cout<<"通知完毕！"<<std::endl;
    // }

}

int main(){

    std::thread t(producer);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk,[]{return ready;});
        std::cout<<"main 被叫醒"<<std::endl;
    }
    t.join();
    return 0;
}


