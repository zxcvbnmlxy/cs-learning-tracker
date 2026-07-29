#include<iostream>
#include<memory>
using namespace std;
struct Node{
    weak_ptr<Node>next;
    ~Node(){cout<<"Node destroyed"<<endl;}
};
int main(){
    shared_ptr<Node>a=make_shared<Node>();
    shared_ptr<Node>b=make_shared<Node>();
    // a.reset();
    cout<<a.use_count()<<endl;
    cout<<"unqiue_ptr"<<endl;
    unique_ptr<int>c=make_unique<int>(42);
    //unique_ptr<int>d=c; //error不能拷贝
    unique_ptr<int>d=move(c);
    int *ptr=d.get();
    cout<<*ptr<<endl;
    return 0;
}