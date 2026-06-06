#!/bin/bash
# ============================================
# g++ 编译命令速查表
# ============================================
# 使用方法: bash gpp_cheatsheet.sh

echo "=============================================="
echo "  g++ 编译命令速查表"
echo "=============================================="

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  1. 基本编译"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  g++ source.cpp                    # 编译为 a.out (Linux) / a.exe (Windows)
  g++ source.cpp -o program         # 指定输出文件名
  g++ source1.cpp source2.cpp       # 编译多个源文件
  g++ *.cpp -o program              # 编译当前目录所有 .cpp
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  2. 分步编译 (四步骤)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  步骤1 — 预处理:  g++ -E source.cpp -o source.i
  步骤2 — 编译:    g++ -S source.i   -o source.s
  步骤3 — 汇编:    g++ -c source.s   -o source.o
  步骤4 — 链接:    g++ source.o -o program

  快捷方式:
  g++ -c source.cpp            # 预处理→编译→汇编 (生成 .o)
  g++ source.o other.o -o app  # 链接 .o 文件
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  3. 常用编译选项"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  -std=c++11       # 指定 C++ 标准 (c++11/14/17/20)
  -Wall -Wextra    # 开启警告
  -Wpedantic       # 严格标准检查
  -Werror          # 警告即错误
  -O0 -O1 -O2 -O3  # 优化级别 (-O2 常用)
  -g               # 生成调试信息
  -I./include      # 添加头文件搜索路径
  -L./lib          # 添加库搜索路径
  -lfoo            # 链接 libfoo.so/a
  -DDEBUG          # 定义宏
  -static          # 静态链接
  -fPIC            # 位置无关代码 (用于 .so)
  -shared          # 生成动态库 (.so / .dll)
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  4. 构建静态库 (.a / .lib)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  # 1. 编译为目标文件
  g++ -c lib.cpp -o lib.o

  # 2. 打包为静态库
  ar rcs libmath.a lib.o

  # 3. 使用静态库
  g++ main.cpp -L. -lmath -o program
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  5. 构建动态库 (.so / .dll / .dylib)"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  Linux (.so):
    g++ -fPIC -shared lib.cpp -o libmath.so

  macOS (.dylib):
    g++ -dynamiclib lib.cpp -o libmath.dylib

  Windows (.dll):
    g++ -shared lib.cpp -o math.dll

  使用动态库:
    g++ main.cpp -L. -lmath -o program
    export LD_LIBRARY_PATH=.  # Linux
    ./program
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  6. 检查编译产物"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  file program        # 查看文件类型
  nm program          # 查看符号表
  ldd program         # 查看动态库依赖 (Linux)
  objdump -d program  # 反汇编
  size program        # 查看各段大小
  strings program     # 提取可打印字符串
EOF

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "  7. 综合示例"
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
cat << 'EOF'
  # 开发调试:
  g++ -std=c++17 -Wall -Wextra -Wpedantic -g -O0 main.cpp -o main_debug

  # 发布:
  g++ -std=c++17 -Wall -O2 -DNDEBUG main.cpp -o main_release

  # 多文件 + 外部库:
  g++ -std=c++17 -O2 \
      -I./include \
      -L./lib \
      -ljson \
      -lpthread \
      main.cpp helper.cpp \
      -o my_app
EOF

echo ""
echo "=============================================="
echo "  提示: 使用 man g++ 查看完整文档"
echo "=============================================="
