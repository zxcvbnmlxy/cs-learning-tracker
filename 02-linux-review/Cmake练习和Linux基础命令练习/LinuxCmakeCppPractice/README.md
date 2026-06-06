# LinuxCmakeCppPractice

一个综合练习项目，用于学习 Linux 基础命令、CMake和 g++ 编译。
## 项目结构
LinuxCmakeCppPractice/
├── README.md                     # 本文件
│
├── linux_basics/                 # 🐧 Linux 基础命令练习
│   ├── 01_file_operations.sh     #   文件与目录操作
│   ├── 02_text_processing.sh     #   文本处理三剑客 (grep/sed/awk)
│   ├── 03_permission_and_links.sh#   权限与链接 (chmod/chown/ln)
│   ├── 04_process_management.sh  #   进程与系统管理 (ps/kill/jobs)
│   └── 05_summary_cheatsheet.sh  #   命令速查表
│
├── cmake_practice/               # 📦 CMake 构建练习
│   ├── CMakeLists.txt            #   根 CMake 配置
│   ├── lib/                      #   静态库模块
│   │   ├── CMakeLists.txt
│   │   ├── math_util.h
│   │   └── math_util.cpp
│   └── app/                      #   可执行程序
│       ├── CMakeLists.txt
│       └── main.cpp
│
└── gpp_practice/                 # 🔨 g++ 编译练习
    ├── helloworld.cpp            #   入门程序
    ├── multi_file/               #   多文件编译
    │   ├── main.cpp
    │   ├── greet.h
    │   └── greet.cpp
    ├── compile_steps/            #   编译流程
    │   ├── steps_demo.sh         #     四步骤详解
    │   └── compile_flags.sh      #     编译选项大全
    ├── Makefile                  #   Makefile 构建
    └── gpp_cheatsheet.sh         #   g++ 速查表
```

---

## 🐧 第一部分：Linux 基础命令练习

所有脚本以 `.sh` 结尾，使用 `bash` 运行：

bash
cd linux_basics

# 文件与目录操作
bash 01_file_operations.sh

# 文本处理 (grep / sed / awk)
bash 02_text_processing.sh

# 权限与链接 (chmod / ln)
bash 03_permission_and_links.sh

# 进程管理
bash 04_process_management.sh

# 速查表
bash 05_summary_cheatsheet.sh
```

> 💡 **建议**：先运行脚本感受命令效果，再用 `man <命令名>` 查看完整手册。

---

## 📦 第二部分：CMake 练习

### CMake 是什么？

CMake 是一个跨平台的构建系统生成器。它不直接编译代码，而是生成 Makefile（或 Visual Studio 项目等）供后续编译使用。

### 练习内容

本项目演示了 CMake 的核心功能：

| 概念 | 文件 | 说明 |
|------|------|------|
| 根配置 | `cmake_practice/CMakeLists.txt` | 项目定义、子目录引入 |
| 静态库 | `cmake_practice/lib/` | 构建 `.a` 静态库 |
| 可执行文件 | `cmake_practice/app/` | 链接库生成程序 |

### 构建与运行

```bash
cd cmake_practice

# 1. 创建并进入构建目录
mkdir -p build && cd build

# 2. 配置项目（生成 Makefile）
cmake ..

# 3. 编译
cmake --build .

# 4. 运行
./bin/MathDemo

### 常用 CMake 命令

```bash
cmake ..                  # 配置（默认 Debug）
cmake .. -DCMAKE_BUILD_TYPE=Release   # 发布模式
cmake --build .           # 编译
cmake --build . --clean-first  # 清理并编译
cmake -B build            # 一步创建 build 目录并配置

# 查看详细编译信息
cmake --build . --verbose

# 安装
cmake --install . --prefix /path/to/install
```

## 🔨 第三部分：g++ 编译练习

```bash
cd gpp_practice

# 最简单的编译
g++ helloworld.cpp -o helloworld
./helloworld
```

### 多文件编译

```bash
# 方法 1：一条命令编译所有源文件
g++ multi_file/main.cpp multi_file/greet.cpp -o greet_app
./greet_app

# 方法 2：分步编译
g++ -c multi_file/main.cpp -o main.o
g++ -c multi_file/greet.cpp -o greet.o
g++ main.o greet.o -o greet_app

# 方法 3：使用 Makefile
make
make run
make clean
```

### 编译四步骤演示

```bash
bash compile_steps/steps_demo.sh
```

### 编译选项大全

```bash
bash compile_steps/compile_flags.sh
```

---

## 💡 学习路线建议

```
初学者
  ├── Linux 基础 → 运行 linux_basics 下的 .sh 脚本
  ├── g++ 入门   → helloworld.cpp + multi_file 多文件编译
  ├── g++ 进阶   → compile_steps 编译选项和四步骤
  └── CMake 进阶 → cmake_practice 多模块构建
```

## 环境要求

- **g++**: 支持 C++11 或更高版本
- **CMake**: 3.10+
- **Bash**: 用于运行练习脚本 (Windows 用户可使用 Git Bash 或 WSL)
