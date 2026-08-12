#include<mutex>      // timed_mutex / unique_lock / defer_lock
#include<chrono>     // seconds / milliseconds
#include<thread>     // thread / this_thread
#include<iostream>
using namespace std;

timed_mutex mtx;   // 会计时的锁 —— 才有 try_lock_for
//懒汉
class Config{
    public:
        static Config* getInstance(){
            if(inst==nullptr){
                inst=new Config();
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
    Config* c1=Config::getInstance(); 
    Config* c2=Config::getInstance();
    if(c1==c2)cout<<"这两是同一个"<<endl;
    return 0;
}
