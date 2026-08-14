#include<mutex>      // timed_mutex / unique_lock / defer_lock
#include<chrono>     // seconds / milliseconds
#include<thread>     // thread / this_thread
#include<iostream>
using namespace std;

timed_mutex mtx;   // 会计时的锁 —— 才有 try_lock_for

mutex mxt2;
//懒汉
class Config{
    public:
        static Config* getInstance(){
        
        if(inst==nullptr){
            lock_guard<mutex> Lock(mxt2);
            if(inst==nullptr){
                inst=new Config();
                }
            }
            return inst;
        }
    private:
        static Config* inst;
        Config(){};
};
Config *Config::inst=nullptr;

//饿汉
class config{

    private:
        config(){};
        static config inst;//声明
    public:
        static config& getInstance(){
            return inst;
        }
};
config config::inst;//定义=程序一开始就构造好的
int main(){
    Config* p1=nullptr,*p2=nullptr;
    thread t1([&]{for(int i=0;i<10000;i++)p1=Config::getInstance();});
    thread t2([&]{for(int i=0;i<10000;i++)p2=Config::getInstance();});
    t1.join();t2.join();

    if(p1==p2)cout<<"这两是同一个"<<endl;
    else cout<<"不是同一个"<<endl;
    return 0;
}
