#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

class String {
    char* data;
public:
    // 构造函数
    String(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
        std::cout << "构造: " << data << "\n";
    }

    // TODO: 析构函数
    ~String() {
        delete[] data;
        // 在这里写
    }

    // TODO: 拷贝构造函数
    String(const String& other) {
        data=new char[strlen(other.data)+1];
        strcpy(data,other.data);
        // 在这里写
    }

    // TODO: 拷贝赋值运算符
    String& operator=(const String& other) {
        if(this==&other){
            return *this;
        }
        delete[] data;
        data=new char[strlen(other.data)+1];
        strcpy(data,other.data);
        // 在这里写
        return *this;
    }

    // TODO: 移动构造函数
    String(String&& other) noexcept {
        data=other.data;
        other.data=nullptr;
        // 在这里写
    }

    // TODO: 移动赋值运算符
    String& operator=(String&& other) noexcept {
        if(this==&other)return *this;
        delete[] data;
        data=other.data;
        other.data=nullptr;
        // 在这里写
        return *this;
    }

    void print() const {
        std::cout << (data ? data : "null") << "\n";
    }
};

#endif
