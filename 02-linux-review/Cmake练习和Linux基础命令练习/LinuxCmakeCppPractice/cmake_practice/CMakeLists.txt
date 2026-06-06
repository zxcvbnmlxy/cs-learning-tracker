# ============================================
# CMake练习 — 根 CMakeLists.txt
# 练习目标：理解 CMake 的项目组织方式
# ============================================
#
# 构建方法:
#   cd cmake_practice
#   mkdir build && cd build
#   cmake ..
#   cmake --build .
#   ./bin/MathDemo
#
# ============================================

# 指定 CMake 最低版本（必备）
cmake_minimum_required(VERSION 3.10)

# 定义项目名称和语言
#   LANGUAGES CXX  → 仅需 C++，不需要 C
#   不写 LANGUAGES 的话默认启用 C 和 CXX
project(CMakePractice VERSION 1.0.0 LANGUAGES CXX)

# 设置 C++ 标准（全局默认）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出路径（可选）
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加子目录
#   顺序重要：lib 必须先于 app（因为 app 依赖 lib）
add_subdirectory(lib)
add_subdirectory(app)

# 打印构建信息
message(STATUS "项目名称: ${PROJECT_NAME}")
message(STATUS "项目版本: ${PROJECT_VERSION}")
message(STATUS "C++ 标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "输出目录: ${CMAKE_BINARY_DIR}")
