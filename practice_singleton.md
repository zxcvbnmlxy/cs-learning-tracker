#include<iostream>
#include<mutex>
#include<atomic>
using namespace std;
class singleton{
    private:
        singleton(){};
        static mutex mtx;
        static std::atomic<singleton*> p;
    public:
        static singleton* instance();
        class Carbo{
        public:
            ~Carbo(){
                if(singleton::p)
                delete singleton::p; 
            }
    };
    static Carbo carbo;
    singleton(const singleton&)=delete;//禁止拷贝构造
    singleton& operator=(const singleton&)=delete;//禁止拷贝赋值
};

std::atomic<singleton*>singleton::p{nullptr};
mutex singleton::mtx;
singleton::Carbo singleton::carbo;
singleton* singleton::instance(){
    singleton* tmp=p.load(memory_order_acquire);
    if(!tmp){
        lock_guard<mutex> lock(singleton::mtx);
        tmp=p.load(memory_order_relaxed);
        if(!tmp){
            tmp=new singleton();
            p.store(tmp,memory_order_release);
        }
    }
    return tmp;
}



/*class singleton{
    private:
        singleton()=default;
        singleton& operator=(const singleton&)=delete;
        singleton(const singleton&)=delete;
    public:
        static singleton& instance(){
            static singleton inst;
            return inst;
        }
};*/

