#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
using namespace std;

mutex mtx;
condition_variable cv;
queue<int>q;
void producer(){
    for(int i=0;i<10;i++){
        unique_lock<mutex> lk(mtx);
        q.push(i);
        cv.notify_one();
    }
    {
        unique_lock<mutex> lk(mtx);
        q.push(-1);
    }
    cv.notify_one();
}

void consumer(){
    while(1){
        int  t;
        {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk,[]{return !q.empty();});
         t=q.front();
        q.pop();
        }
        if(t==-1)break;
        cout<<"处理任务"<<t<<endl;
       
    }
    cout<<"任务完成"<<endl;
}
int main(){
    thread t1(producer),t2(consumer);
    t1.join();
    t2.join();
    return 0;
}