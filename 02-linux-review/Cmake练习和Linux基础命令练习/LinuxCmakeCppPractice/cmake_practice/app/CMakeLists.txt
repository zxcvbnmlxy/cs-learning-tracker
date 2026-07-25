add_executable(MathDemo main.cpp) #将main.cpp编译成可执行文件，叫MathDemo
target_link_libraries(MathDemo PRIVATE MathUtils) #MathDemo这个可执行文件要链接MathUtils库 