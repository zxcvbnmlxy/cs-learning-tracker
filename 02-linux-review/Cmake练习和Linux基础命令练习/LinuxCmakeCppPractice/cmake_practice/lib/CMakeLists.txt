# ============================================
# lib/CMakeLists.txt — 构建静态库
# ============================================

# 1. 收集源文件
#    使用 file(GLOB ...) 自动收集 .cpp 文件
file(GLOB MATH_SOURCES "*.cpp")

# 2. 创建静态库目标
#    STATIC  → 静态库 (.a / .lib)
#    SHARED  → 动态库 (.so / .dll)
add_library(MathUtils STATIC ${MATH_SOURCES})

# 3. 指定头文件目录（供其他目标引用）
#    PUBLIC  → 这个库的使用者也可见
target_include_directories(MathUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 4. 设置编译选项（对本库生效）
target_compile_features(MathUtils PUBLIC cxx_std_11)
target_compile_options(MathUtils PRIVATE -Wall -Wextra -Wpedantic)

# 5. 设置输出名称（可选）
set_target_properties(MathUtils PROPERTIES
    OUTPUT_NAME "math_utils"
    VERSION "1.0.0"
)
