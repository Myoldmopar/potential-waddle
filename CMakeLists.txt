cmake_minimum_required(VERSION 3.14)
project(TestSchedulingStuff)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        TestSchedulingStuff
        include/base.h include/case1.h include/case2.h include/case3.h include/case4.h include/case5.h
        src/main.cpp src/case1.cpp src/case2.cpp src/case3.cpp src/case4.cpp src/case5.cpp
        )

include_directories(include)
