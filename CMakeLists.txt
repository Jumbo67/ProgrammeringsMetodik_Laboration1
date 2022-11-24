cmake_minimum_required(VERSION 3.23)
project(C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(C__
        main.cpp int_buffer.cpp int_buffer.h int_sorted.cpp int_sorted.h)
