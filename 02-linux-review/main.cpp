#include "src/memory_demo.h"

int main() {
    std::cout << "═══════════════════════════════════════════\n";
    std::cout << "   C++ 内存管理综合练习\n";
    std::cout << "═══════════════════════════════════════════\n";

    demo_raw_pointer();
    demo_unique_ptr();
    demo_shared_ptr();

    // 演示 Buffer 类
    std::cout << "\n========== 4. RAII —— Buffer 类演示 ==========\n";
    Buffer b1(3);
    b1.fill(10);
    b1.print();

    Buffer b2 = std::move(b1);  // 移动语义
    std::cout << "  移动后 b2:";
    b2.print();

    demo_memory_leak();
    demo_correct_way();
    practice_unique_ptr();
    practice_shared_ptr();

    std::cout << "\n═══════════════════════════════════════════\n";
    std::cout << "  练习结束！所有资源已正确释放 ✅\n";
    std::cout << "═══════════════════════════════════════════\n";
    return 0;
}
