// ============================================
// g++ 练习 1: 最简单的 C++ 程序
// ============================================
//
// 编译并运行:
//   g++ helloworld.cpp -o helloworld
//   ./helloworld          (Linux/macOS)
//   helloworld.exe        (Windows)
//
// 添加警告和标准:
//   g++ -std=c++11 -Wall -Wextra -Wpedantic helloworld.cpp -o helloworld
//
// ============================================

#include <iostream>

int main() {
    std::cout << "Hello, g++!" << std::endl;
    std::cout << "C++ Standard: " << __cplusplus << std::endl;

    // __cplusplus 值含义:
    //   199711L → C++98
    //   201103L → C++11
    //   201402L → C++14
    //   201703L → C++17
    //   202002L → C++20

    return 0;
}
