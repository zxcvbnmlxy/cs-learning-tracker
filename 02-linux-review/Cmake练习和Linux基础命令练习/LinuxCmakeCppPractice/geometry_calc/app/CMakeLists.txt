# 把 main.cpp 编译成可执行文件，名叫 GeoApp
add_executable(GeoApp main.cpp)

# 把 Geometry 库链接进来，main.cpp 里调用的几何函数才能找到
# PRIVATE = 链接只在 GeoApp 需要，不往下传
target_link_libraries(GeoApp PRIVATE Geometry)
