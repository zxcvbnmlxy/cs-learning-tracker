#include<iostream>
#include<string>
using namespace std;

class student{
    public:
    double score;
    static int count;
    student(int ID,string Name):id(ID),name(Name){
        count++;
        return ;
    }
    student& setScore(double s){
        score=s;
        return *this;
    }
    student& setName(string n){
        name=n;
        return *this;
    }
    
    friend ostream& operator<<(ostream &os,const student &s){
        os<<"id:"<<s.id<<endl;
        os<<"name:"<<s.name<<endl;
        os<<"score:"<<s.score<<endl;
        return os;
    }
    ~student(){
        cout<<"student destroyed"<<endl;
    }
    private:
    const int id;
    string name;
};
int student::count=0;
int main(){
    student a(1,"zhangsan");
    student b(2,"lisi");
    a.setScore(90);
    b.setScore(85);
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<student::count<<endl;
    return 0;
}