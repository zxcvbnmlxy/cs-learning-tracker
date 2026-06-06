#include "math_util.h"
#include <iostream>
#include <vector>

int main() {
    std::cout << "\n";
    math::print_separator("CMake 练习项目 — 数学工具演示");

    // ---- 基本运算 ----
    math::print_separator("基本运算");
    std::cout << "▶ max(10, 20)   = " << math::max(10, 20) << std::endl;
    std::cout << "▶ min(10, 20)   = " << math::min(10, 20) << std::endl;
    std::cout << "▶ square(7)     = " << math::square(7) << std::endl;
    std::cout << "▶ cube(5)       = " << math::cube(5) << std::endl;

    // ---- 数学判断 ----
    math::print_separator("数学判断");
    for (int n : {2, 3, 4, 17, 97, 100}) {
        std::cout << "▶ is_prime(" << n << ") = "
                  << (math::is_prime(n) ? "true" : "false") << std::endl;
    }

    // ---- 数论 ----
    math::print_separator("数论");
    std::cout << "▶ gcd(48, 18)   = " << math::gcd(48, 18) << std::endl;
    std::cout << "▶ lcm(12, 18)   = " << math::lcm(12, 18) << std::endl;

    // ---- 斐波那契 ----
    math::print_separator("斐波那契数列");
    std::cout << "▶ fibonacci(0)  = " << math::fibonacci(0) << std::endl;
    std::cout << "▶ fibonacci(1)  = " << math::fibonacci(1) << std::endl;
    std::cout << "▶ fibonacci(10) = " << math::fibonacci(10) << std::endl;
    std::cout << "▶ fibonacci(20) = " << math::fibonacci(20) << std::endl;

    // ---- 统计 ----
    math::print_separator("统计分析");
    std::vector<int> data = {85, 92, 78, 90, 88, 95, 80, 87};
    std::cout << "▶ 数据: {85, 92, 78, 90, 88, 95, 80, 87}" << std::endl;
    std::cout << "▶ average()     = " << math::average(data) << std::endl;
    std::cout << "▶ stddev()      = " << math::stddev(data) << std::endl;

    math::print_separator();
    std::cout << "✅ CMake 练习项目运行成功！\n" << std::endl;

    return 0;
}
