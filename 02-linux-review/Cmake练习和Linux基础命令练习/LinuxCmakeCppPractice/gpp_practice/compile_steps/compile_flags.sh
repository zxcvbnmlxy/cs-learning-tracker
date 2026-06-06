#!/bin/bash
# ============================================
# g++ 常用编译选项详解
# ============================================
# 使用方法: bash compile_flags.sh

echo "========================================="
echo "  g++ 常用编译选项大全"
echo "========================================="

# ---------- 准备测试文件 ----------
cat > test_flags.cpp << 'EOF'
#include <iostream>

// 故意遗留一些"问题"来展示警告
int main() {
    int x;            // 未初始化变量
    int arr[5];       // 声明了未使用

    std::cout << "编译选项演示" << std::endl;

    // 使用了旧式 C 风格转换
    double d = (double)5 / 3;

    // 有符号/无符号比较
    int a = -1;
    unsigned int b = 1;
    if (a < b) {
        std::cout << "有符号/无符号比较" << std::endl;
    }

    return 0;
}
EOF

echo ""
echo "========= 1. -std= — 指定 C++ 标准 ========="
echo "  g++ -std=c++11  test.cpp   # C++11"
echo "  g++ -std=c++14  test.cpp   # C++14"
echo "  g++ -std=c++17  test.cpp   # C++17"
echo "  g++ -std=c++20  test.cpp   # C++20"
echo "  g++ -std=gnu++17           # C++17 + GNU扩展"

echo ""
echo "========= 2. 警告选项 ========="
echo "  -Wall        # 开启大多数常见警告"
echo "  -Wextra      # 开启额外警告"
echo "  -Wpedantic   # 严格遵循标准"
echo "  -Werror      # 将所有警告视为错误"
echo "  -w           # 关闭所有警告（不推荐）"
echo ""

echo "编译 test_flags.cpp 的警告输出:"
g++ -std=c++11 -Wall -Wextra -Wpedantic test_flags.cpp -o test_flags 2>&1 || true
echo ""

echo "使用 -Werror 会将警告视为错误:"
g++ -std=c++11 -Wall -Werror test_flags.cpp -o test_flags 2>&1 && echo "  编译成功" || echo "  编译失败（因为警告被当作错误）"
echo ""

echo "========= 3. -O 优化级别 ========="
echo "  -O0      # 不优化（默认，调试用）"
echo "  -O1      # 轻度优化"
echo "  -O2      # 中度优化（常用）"
echo "  -O3      # 最高优化"
echo "  -Os      # 优化体积"
echo "  -Ofast   # 极致优化（可能违反标准）"

echo ""
echo "比较不同优化级别的编译产物大小:"
for opt in O0 O1 O2 O3 Os; do
    g++ -std=c++11 -${opt} test_flags.cpp -o test_flags_${opt}
    size=$(stat -f%z test_flags_${opt} 2>/dev/null || stat --printf="%s" test_flags_${opt} 2>/dev/null)
    echo "  -${opt}: ${size} bytes"
done

echo ""
echo "========= 4. -g — 调试信息 ========="
echo "  -g         # 生成调试信息 (供 GDB 使用)"
echo "  -g3        # 生成更多调试信息（宏定义等）"
echo "  -ggdb      # GDB 专用调试信息"
echo ""
g++ -std=c++11 -g test_flags.cpp -o test_flags_debug
echo "  已生成带调试信息的 test_flags_debug"
ls -lh test_flags_debug

echo ""
echo "========= 5. -o — 指定输出文件名 ========="
echo "  g++ source.cpp              # 默认输出 a.out (Linux) 或 a.exe (Windows)"
echo "  g++ source.cpp -o program   # 指定输出名为 program"

echo ""
echo "========= 6. -I — 添加头文件搜索路径 ========="
echo "  g++ -I./include -I../lib/include main.cpp"
echo "  编译器会在以下顺序查找头文件:"
echo "    1) -I 指定的目录（从左到右）"
echo "    2) 系统头文件目录 (/usr/include 等)"

echo ""
echo "========= 7. -L 和 -l — 链接库 ========="
echo "  -L./lib        # 添加库搜索路径"
echo "  -lmath         # 链接 libmath.a (或 libmath.so)"
echo "  -static        # 静态链接"
echo "  示例: g++ main.cpp -L./lib -lmath -o program"

echo ""
echo "========= 8. -D — 定义宏 ========="
echo "  g++ -DDEBUG main.cpp            # 定义 DEBUG 宏"
echo "  g++ -DVERSION=\\\"1.0\\\" main.cpp  # 定义 VERSION 为 \"1.0\""
echo ""

cat > macro_test.cpp << 'EOF'
#include <iostream>
int main() {
#ifdef DEBUG
    std::cout << "调试模式" << std::endl;
#else
    std::cout << "发布模式" << std::endl;
#endif
    return 0;
}
EOF

echo "不定义 DEBUG:"
g++ macro_test.cpp -o macro_test && ./macro_test
echo "定义 DEBUG:"
g++ -DDEBUG macro_test.cpp -o macro_test && ./macro_test

echo ""
echo "========= 9. 综合示例 — 完整的编译命令 ========="
echo "  g++ \\"
echo "    -std=c++17 \\"
echo "    -Wall -Wextra -Wpedantic -Werror \\"
echo "    -O2 \\"
echo "    -g \\"
echo "    -I./include \\"
echo "    -L./lib \\"
echo "    -lmath_utils \\"
echo "    -DRELEASE \\"
echo "    main.cpp helper.cpp \\"
echo "    -o my_program"

# ---------- 清理 ----------
echo ""
echo "清理临时文件..."
rm -f test_flags.cpp test_flags test_flags_O0 test_flags_O1 test_flags_O2 test_flags_O3 test_flags_Os test_flags_debug macro_test.cpp macro_test

echo ""
echo "✅ 编译选项演示完成！"
