add_library(MathUtils STATIC math_util.cpp) # 把math_utils.cpp编译成一个静态库，叫MathUtils
target_include_directories(MathUtils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})