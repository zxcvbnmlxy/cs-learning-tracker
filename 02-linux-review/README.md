# Linux C++ 练习项目

> WSL Ubuntu 24.04 + g++ 13.3 + CMake 3.28

## 📦 项目结构

```
memory_demo/
├── main.cpp              # 主入口
├── src/
│   ├── memory_demo.h     # 头文件
│   └── memory_demo.cpp   # 实现（内存管理示例）
├── CMakeLists.txt        # CMake 构建
├── Makefile              # Make 构建
└── .vscode/              # VSCode 配置
    ├── tasks.json        # 构建/Git 任务
    ├── launch.json       # 调试配置
    ├── c_cpp_properties.json  # IntelliSense
    └── extensions.json   # 推荐扩展
```

## 🎯 练习内容

### 编译方法（3种）
```bash
# 1. g++ 直接编译
g++ -std=c++17 main.cpp src/memory_demo.cpp -o demo && ./demo

# 2. Makefile
make && make run

# 3. CMake
cmake -B build && cmake --build build && ./build/memory_demo
```

### 内存管理
- `new/delete` 原始指针
- `unique_ptr` 独占所有权
- `shared_ptr` / `weak_ptr` 共享所有权
- RAII Buffer 类
- 正确 vs 错误写法对比

### Git 练习
```bash
# 查看分支图
git log --oneline --all --graph --decorate

# 创建新分支
git checkout -b feature/练习名

# 提交
git add . && git commit -m "描述"

# 合并到主分支
git checkout master && git merge feature/练习名
```

## 🎮 VSCode 操作

| 操作 | 快捷键/方式 |
|------|------------|
| 构建 | `Ctrl+Shift+B` |
| 运行 | 终端输入 `./build/memory_demo` |
| 调试 | `F5` |
| Git 分支图 | `Ctrl+Shift+P` → `Git Graph` |
| 函数调用链 | 选中函数 → `Shift+Alt+H` |
| 跳转定义 | 在符号上按 `F12` |
| 查看大纲 | `Ctrl+Shift+O` |
