#include "String.h"

int main() {
    std::cout << "=== 构造 ===\n";
    String s1("hello");
    String s2("world");

    std::cout << "\n=== 拷贝构造 ===\n";
    String s3 = s1;
    s3.print();

    std::cout << "\n=== 拷贝赋值 ===\n";
    s2 = s1;
    s2.print();

    std::cout << "\n=== 移动构造 ===\n";
    String s4 = std::move(s1);
    s4.print();

    std::cout << "\n=== 移动赋值 ===\n";
    String s5("temp");
    s5 = std::move(s2);
    s5.print();

    std::cout << "\n=== 结束，看析构顺序 ===\n";
    return 0;
}
