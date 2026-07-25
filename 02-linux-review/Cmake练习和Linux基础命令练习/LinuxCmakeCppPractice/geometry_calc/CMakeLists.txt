cmake_minimum_required(VERSION 3.28)  # 指定 CMake 最低版本，低于 3.28 会报错
project(GeometryCalc LANGUAGES CXX)   # 项目名 GeometryCalc，只启用 C++
add_subdirectory(lib)                 # 去 lib/ 目录执行它的 CMakeLists.txt
add_subdirectory(app)                 # 去 app/ 目录执行它的 CMakeLists.txt
