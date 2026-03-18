cmake_minimum_required(VERSION 3.20)
project(SimpleClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimpleClass main.cpp SimpleClass.cpp SimpleClass.h)

target_compile_options(SimpleClass PRIVATE
        -fsanitize=address
        -g
        -fno-omit-frame-pointer
        -O1
)

target_link_options(SimpleClass PRIVATE
        -fsanitize=address
)
