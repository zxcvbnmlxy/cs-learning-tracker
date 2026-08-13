#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>
using namespace std;
//由于t1,t2是并行的,比如t1对mxt1加锁后,同时线程t2对mtx2加锁,然后t1继续执行,对mtx2加锁,此时t1等待t2释放mtx2,t2等待t1释放mtx1,造成死锁
//死锁,由于.lock()是阻塞的,.lock()的顺序不一致,导致线程1锁mtx1后,线程2锁mtx2,线程1等待线程2释放mtx2,线程2等待线程1释放mtx1,造成死锁
mutex mtx1,mtx2;

void work1(){
    lock_guard<mutex> Lock1(mtx2);
    lock_guard<mutex> Lock2(mtx1);
    
    this_thread::sleep_for(chrono::milliseconds(100));
    cout<<"work1 done"<<endl;
}
void work2(){
    lock_guard<mutex> Lock1(mtx1);
    lock_guard<mutex> Lock2(mtx2);
    this_thread::sleep_for(chrono::milliseconds(100));
    cout<<"work2 done"<<endl;
}

int main(){
    thread t1(work1);
    thread t2(work2);
    t1.join();
    t2.join();  
    cout<<"main done"<<endl;
}