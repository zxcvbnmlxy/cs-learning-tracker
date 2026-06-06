#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <vector>
#include <string>

namespace math {

/// 返回两个整数的最大值
int max(int a, int b);

/// 返回两个整数的最小值
int min(int a, int b);

/// 计算整数的平方
int square(int x);

/// 计算整数的立方
int cube(int x);

/// 判断一个数是否为素数
bool is_prime(int n);

/// 计算最大公约数 (欧几里得算法)
int gcd(int a, int b);

/// 计算最小公倍数
int lcm(int a, int b);

/// 斐波那契数列第 n 项 (n 从 0 开始)
int fibonacci(int n);

/// 计算一组数的平均值
double average(const std::vector<int>& nums);

/// 计算一组数的标准差
double stddev(const std::vector<int>& nums);

/// 打印分隔线
void print_separator(const std::string& title = "");

} // namespace math

#endif // MATH_UTIL_H
