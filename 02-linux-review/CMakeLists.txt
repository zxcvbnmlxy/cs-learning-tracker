cmake_minimum_required(VERSION 3.10)
project(MemoryDemo CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(memory_demo
    main.cpp
    src/memory_demo.cpp
)
