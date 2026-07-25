#include "String.h"
#include <vector>

int main() {
    std::vector<String> v;

    std::cout << "=== push_back 拷贝（10次）===\n";
    String s("hello");
    for (int i = 0; i < 10; i++) {
        v.push_back(s);   // 每次拷贝
    }

    std::cout << "\n=== emplace_back 直接构造（不拷贝不移动）===\n";
    std::vector<String> v2;
    v2.emplace_back("hello");
    v2.emplace_back("world");

    std::cout << "\n=== 结束 ===\n";
    return 0;
}
