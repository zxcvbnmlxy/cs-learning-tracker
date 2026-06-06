#!/bin/bash
# ============================================
# g++ 编译四步骤详解
# ============================================
# 源文件(.cpp) → 可执行文件 的完整流程
#
#   预处理 (.i) → 编译 (.s) → 汇编 (.o) → 链接
#   g++ -E      g++ -S      g++ -c       g++
#
# ============================================

echo "========================================="
echo "  g++ 编译四步骤详解"
echo "========================================="

# ---------- 准备测试文件 ----------
cat > demo.cpp << 'EOF'
#include <iostream>
#define PI 3.14159

inline double circle_area(double r) {
    return PI * r * r;
}

int main() {
    std::cout << "编译步骤演示" << std::endl;
    std::cout << "圆的面积: " << circle_area(5.0) << std::endl;
    return 0;
}
EOF

echo ""
echo "源代码 (demo.cpp):"
cat demo.cpp

# ---------- 步骤 1: 预处理 ----------
echo ""
echo "========================================="
echo "  步骤 1 — 预处理 (g++ -E)"
echo "========================================="
echo "  作用: 展开 #include、#define 宏、处理条件编译"
echo "  输出: demo.i (文本文件，比源文件大很多)"
echo ""

g++ -E demo.cpp -o demo.i 2>&1 || true
echo "  预处理结果 (demo.i 前 20 行):"
head -20 demo.i
echo "  ... (共 $(wc -l < demo.i) 行)"
echo ""
echo "  可以看到:"
echo "  - #include <iostream> 被替换为上千行的头文件内容"
echo "  - PI 被替换为 3.14159"
echo "  - 注释被删除"

# ---------- 步骤 2: 编译 ----------
echo ""
echo "========================================="
echo "  步骤 2 — 编译 (g++ -S)"
echo "========================================="
echo "  作用: 将预处理后的代码翻译为汇编语言"
echo "  输出: demo.s (汇编代码)"
echo ""

g++ -S demo.i -o demo.s 2>&1 || true
echo "  编译结果 (demo.s 汇编代码):"
cat demo.s

# ---------- 步骤 3: 汇编 ----------
echo ""
echo "========================================="
echo "  步骤 3 — 汇编 (g++ -c)"
echo "========================================="
echo "  作用: 将汇编代码转换为机器码 (目标文件)"
echo "  输出: demo.o (二进制文件)"
echo ""

g++ -c demo.s -o demo.o 2>&1 || true
echo "  汇编完成，生成 demo.o"
echo "  file 命令识别: $(file demo.o 2>/dev/null || echo '二进制目标文件')"
echo "  用 nm 查看符号表:"
nm -C demo.o 2>/dev/null | head -10

# ---------- 步骤 4: 链接 ----------
echo ""
echo "========================================="
echo "  步骤 4 — 链接 (g++)"
echo "========================================="
echo "  作用: 将多个目标文件和库链接为可执行文件"
echo "  输出: demo_program (可执行文件)"
echo ""

g++ demo.o -o demo_program 2>&1 || true
echo "  链接完成，生成 demo_program"
ls -lh demo_program

# ---------- 运行 ----------
echo ""
echo "========================================="
echo "  运行最终程序"
echo "========================================="
./demo_program

# ---------- 一键编译 ----------
echo ""
echo "========================================="
echo "  一键编译 (等价于以上四步)"
echo "========================================="
echo "  g++ demo.cpp -o demo_program"
echo ""
echo "  g++ 自动完成: 预处理 → 编译 → 汇编 → 链接"

# ---------- 清理 ----------
rm -f demo.cpp demo.i demo.s demo.o demo_program

echo ""
echo "✅ 编译步骤演示完成！"
echo ""
echo "总结:"
echo "  .cpp  ──(-E)──▶  .i   ──(-S)──▶  .s   ──(-c)──▶  .o   ──(ld)──▶  executable"
echo "  源文件     预处理    纯C++    编译    汇编    汇编    链接     可执行文件"
