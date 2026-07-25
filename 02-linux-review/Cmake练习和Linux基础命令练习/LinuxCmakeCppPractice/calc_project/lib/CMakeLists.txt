add_library(CalcLib STATIC calc.cpp)
target_include_directories(CalcLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
