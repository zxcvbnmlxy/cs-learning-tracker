#include<iostream>
#include<string>
#include<memory>
using namespace std;
template<typename T>class Myvector{
    public:
    Myvector():size(0),capacity(0),data(nullptr){};
    Myvector(int s):size(s),capacity(s*2){
        data=new T[capacity];
    };
    Myvector(const Myvector &other):size(other.size),capacity(other.capacity){
        data=new T[capacity];
        for(int i=0;i<size;i++){
            data[i]=other.data[i];
        }
    }
    Myvector( Myvector &&other):size(other.size),capacity(other.capacity){
        data=other.data;
        other.data=nullptr;
        other.size=0;
        other.capacity=0;
    }
    ~Myvector(){delete[] data;};
    Myvector& operator=(const Myvector &other){
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
    T& operator[](int index){
        if(index<0||index>=size){
            throw out_of_range("index out of range");
        }
        return data[index];
    }
    Myvector& operator=(Myvector &&other)noexcept{
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
    friend ostream& operator<<(ostream &os,const Myvector& v){
        for(int i=0;i<v.size;i++){
            os<<v.data[i]<<" ";
        }
        return os;
    };
    int getSize(){return size;};
    void push_back(const T &value){
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
    void pop_back(){
        if(size==0)return;
        size--;    
    }
    private:
    int size;
    int capacity;
    T* data;
};
int main(){
    Myvector<shared_ptr<string>>v;
    v.push_back(make_shared<string>("C++"));
    v.push_back(make_shared<string>("复习"));
    v.push_back(make_shared<string>("完成"));
    for(int i=0;i<v.getSize();i++){
        cout<<*v[i];
    }
    return 0;
}