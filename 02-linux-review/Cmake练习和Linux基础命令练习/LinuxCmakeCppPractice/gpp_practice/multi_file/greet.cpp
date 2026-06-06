// ============================================
// g++ 练习 2: 多文件编译 — 实现文件
// ============================================

#include "greet.h"
#include <iostream>
#include <ctime>

void greet(const std::string& name) {
    std::cout << "👋 Hello, " << name << "! Welcome to g++ practice." << std::endl;
}

void farewell(const std::string& name) {
    std::cout << "👋 Goodbye, " << name << "! See you next time." << std::endl;
}

void greet_with_time(const std::string& name) {
    std::time_t now = std::time(nullptr);
    std::cout << "🕐 " << name << ", the current time is: "
              << std::ctime(&now);
}
