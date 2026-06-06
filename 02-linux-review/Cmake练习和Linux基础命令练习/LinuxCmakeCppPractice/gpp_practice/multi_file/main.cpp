// ============================================
// g++ 练习 2: 多文件编译 — 主文件
// ============================================
//
// 编译方式（三种）:
//
// 方法 1 — 一条命令编译所有源文件:
//   g++ main.cpp greet.cpp -o greet_app
//
// 方法 2 — 先编译为 .o 目标文件，再链接（分步骤）:
//   g++ -c main.cpp      → 生成 main.o
//   g++ -c greet.cpp     → 生成 greet.o
//   g++ main.o greet.o -o greet_app
//
// 方法 3 — 使用 Makefile (见 gpp_practice/compile_steps/)
//
// ============================================

#include "greet.h"
#include <iostream>

int main() {
    std::cout << "\n=== g++ 多文件编译演示 ===\n" << std::endl;

    greet("Alice");
    greet_with_time("Bob");
    farewell("Charlie");

    std::cout << "\n✅ 多文件编译成功！" << std::endl;
    return 0;
}
