#include<iostream>
#include<memory>
using namespace std;
int main(){
    shared_ptr<int>p=make_shared<int>(42);
    cout<<"p value: "<<*p<<endl;
    cout<<"p use_count: "<<p.use_count()<<endl;
    {
        shared_ptr<int>q=p;
        cout<<"p inside use_count "<<p.use_count()<<endl;
    }
    cout<<"p outside use_count "<<p.use_count()<<endl;
    return 0;
}