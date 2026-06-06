#include "math_util.h"
#include <cmath>
#include <iostream>

namespace math {

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int square(int x) {
    return x * x;
}

int cube(int x) {
    return x * x * x;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return std::abs(a * b) / gcd(a, b);
}

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}

double average(const std::vector<int>& nums) {
    if (nums.empty()) return 0.0;
    double sum = 0.0;
    for (int n : nums) sum += n;
    return sum / nums.size();
}

double stddev(const std::vector<int>& nums) {
    if (nums.empty()) return 0.0;
    double avg = average(nums);
    double sum_sq = 0.0;
    for (int n : nums) {
        sum_sq += (n - avg) * (n - avg);
    }
    return std::sqrt(sum_sq / nums.size());
}

void print_separator(const std::string& title) {
    const int WIDTH = 50;
    if (title.empty()) {
        std::cout << std::string(WIDTH, '=') << std::endl;
    } else {
        int padding = (WIDTH - 2 - static_cast<int>(title.length())) / 2;
        std::cout << std::string(padding, '=') << " "
                  << title << " "
                  << std::string(WIDTH - 2 - padding - title.length(), '=')
                  << std::endl;
    }
}

} // namespace math
