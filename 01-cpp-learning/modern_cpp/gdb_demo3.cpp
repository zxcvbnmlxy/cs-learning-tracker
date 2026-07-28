// GDB bt演示 — 故意制造段错误
#include <iostream>
using namespace std;

void func3(int* p){
    *p = 42;        // 如果p是nullptr，这里崩溃
}

void func2(int* p){
    func3(p);
}

void func1(){
    func2(nullptr); // 传空指针
}

int main(){
    func1();
    return 0;
}
