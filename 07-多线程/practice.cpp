#include<mutex>
#include<thread>
#include<iostream>
using namespace std;

mutex mtx;
timed_mutex tmtx;
int ans=0;
void func(int x){

}
//线程函数：对共享资源进行加法操作，使用lock_guard进行加锁，保证线程安全(自动加锁解锁)
void func2(){
    for(int i=0;i<10000000;i++){
        //error lock_guard<mutex> Lock(mtx,adopt_lock);//adpot_lock表示已经上锁了,都没上锁导致数据竞争,但是要求保证已经手动上过锁
        lock_guard<mutex> Lock(mtx);//上锁
        ans++;
    }
}
//线程函数：对共享资源进行加法操作，使用unique_lock进行加锁，保证线程安全(自动加锁解锁)
void func3(){
    for(int i=0;i<2;i++){
        unique_lock<timed_mutex> Lock(tmtx,defer_lock);//上锁
        if(Lock.try_lock_for(chrono::seconds(3))){//尝试上锁,如果3秒内没上锁成功就放弃
            this_thread::sleep_for(chrono::seconds(1));//模拟耗时操作
            ans++;
        }
    }
}
int main(){
    thread t1(func3);
    thread t2(func3);
    t2.join();
    t1.join();
    cout<<"ans="<<ans<<endl;
    return 0;
}