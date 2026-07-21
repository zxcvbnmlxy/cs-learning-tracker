#include<iostream>
#include<cstring>
using namespace std;

class Mystring{
    public:
    //构造函数
    Mystring(const char*c){
        str=new char[strlen(c)+1];
        strcpy(str,c);
    }
    //拷贝构造函数
    Mystring(const Mystring &other){
        size_t len=strlen(other.str);
        str=new char[len+1];
        strcpy(str,other.str);
    }
    //移动构造函数
    Mystring (Mystring &&other)noexcept{
        str=other.str;
        other.str=nullptr;
    }
    //默认构造函数
    Mystring(){
        str=new char[1];
        str[0]='\0';
    }
    //拷贝赋值运算符(将拷贝对象的内容化为己有，但是对方不改变)    
    Mystring &operator=(const Mystring &other){
        if(this==&other){
            return *this;
        }
        delete[] str;
        size_t len=strlen(other.str);
        str=new char[len+1];
        strcpy(str,other.str);
        return *this;
    }
    //移动赋值运算符(将要移动的对象置空，将其指针化为己用)
    Mystring &operator=( Mystring &&other)noexcept{
        if(this==&other){
            return *this;
        }
        delete[]str;
        str=other.str;//将other的str指针赋值给当前对象的str
        other.str=nullptr;//将other的str置为NULL，防止析构时释放内存
        return *this;
    }
    void print(){
        cout<<str<<endl;
    }
    //析构函数
    ~Mystring(){
        delete[] str;
    }
private:
    char* str;
};
int main(){
    Mystring a("hello");
    a.print();
    // Mystring b=a;//调用拷贝构造函数
    Mystring b(std::move(a));//移动构造
    b.print();
    return 0;
}
