# ============================================
# app/CMakeLists.txt — 构建可执行文件
# ============================================

# 1. 收集源文件
file(GLOB APP_SOURCES "*.cpp")

# 2. 创建可执行目标
add_executable(MathDemo ${APP_SOURCES})

# 3. 链接库
#    target_link_libraries 会自动处理 include 路径传递
target_link_libraries(MathDemo PRIVATE MathUtils)

# 4. 编译选项
target_compile_features(MathDemo PRIVATE cxx_std_11)
target_compile_options(MathDemo PRIVATE -Wall -Wextra -Wpedantic)

# 5. 设置输出目录（build 目录下的 bin/）
set_target_properties(MathDemo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
