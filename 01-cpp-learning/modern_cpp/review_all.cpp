#include<iostream>
#include<string>
#include<memory>
using namespace std;
// 模板类 —— 支持任意类型T
template<typename T>class Myvector{
    public:
    Myvector():size(0),capacity(0),data(nullptr){};      // 默认构造
    Myvector(int s):size(s),capacity(s*2){                // 有参构造
        data=new T[capacity];
    };
    Myvector(const Myvector &other):size(other.size),capacity(other.capacity){  // 拷贝构造（深拷贝）
        data=new T[capacity];
        for(int i=0;i<size;i++){
            data[i]=other.data[i];
        }
    }
    Myvector( Myvector &&other):size(other.size),capacity(other.capacity){      // 移动构造（偷指针）
        data=other.data;
        other.data=nullptr;
        other.size=0;
        other.capacity=0;
    }
    ~Myvector(){delete[] data;};                          // 析构
    Myvector& operator=(const Myvector &other){           // 拷贝赋值
        if(this==&other){
            return *this;
        }
        delete[] data;
        size=other.size;
        capacity=other.capacity;
        data=new T[capacity];
        for(int i=0;i<size;i++){
            data[i]=other.data[i];
        }
        return *this;
    }
    T& operator[](int index){                             // 下标访问
        if(index<0||index>=size){
            throw out_of_range("index out of range");
        }
        return data[index];
    }
    Myvector& operator=(Myvector &&other)noexcept{        // 移动赋值（noexcept标记）
        if(this==&other){
            return *this;
        }
        delete[] data;
        data=other.data;
        size=other.size;
        capacity=other.capacity;
        other.data=nullptr;
        other.size=0;
        other.capacity=0;
        return *this;
    }
    friend ostream& operator<<(ostream &os,const Myvector& v){  // 友元输出
        for(int i=0;i<v.size;i++){
            os<<v.data[i]<<" ";
        }
        return os;
    };
    int getSize(){return size;};                          // 获取大小
    void push_back(const T &value){                       // 尾部插入（×2扩容）
        if(size==capacity){
            capacity=(capacity==0)?1:capacity*2;
            T* newData=new T[capacity];
            for(int i=0;i<size;i++){
                newData[i]=data[i];
            }
            delete[] data;
            data=newData;
        }
        data[size]=value;
        size++;
    }
    void pop_back(){                                      // 尾部删除
        if(size==0)return;
        size--;
    }
    private:
    int size;       // 当前元素数
    int capacity;   // 当前容量
    T* data;        // 动态数组指针
};
int main(){
    Myvector<shared_ptr<string>>v;                        // 模板 + 智能指针
    v.push_back(make_shared<string>("C++"));              // make_shared创建
    v.push_back(make_shared<string>("复习"));
    v.push_back(make_shared<string>("完成"));
    for(int i=0;i<v.getSize();i++){
        cout<<*v[i];                                       // 解引用shared_ptr取值
    }
    return 0;
}
