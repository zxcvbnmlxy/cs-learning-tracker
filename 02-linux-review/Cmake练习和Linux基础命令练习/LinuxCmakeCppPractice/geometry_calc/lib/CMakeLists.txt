# 把 geometry.cpp 编译成静态库，库名叫 Geometry
# STATIC = 静态库(.a)，SHARED = 动态库(.so/.dll)
add_library(Geometry STATIC geometry.cpp)

# 把 lib/ 目录标记为头文件路径，Geometry 和链接它的目标都能找到 geometry.h
# PUBLIC = 当前目标和链接者都可见
target_include_directories(Geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
