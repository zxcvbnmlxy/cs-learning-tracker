// ============================================
// g++ 练习 2: 多文件编译 — 头文件
// ============================================
// 防止重复包含的宏（#include guard）
#ifndef GREET_H
#define GREET_H

#include <string>

/// 问候函数声明
void greet(const std::string& name);

/// 告别函数声明
void farewell(const std::string& name);

/// 当前时间问候
void greet_with_time(const std::string& name);

#endif // GREET_H
