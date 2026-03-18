cmake_minimum_required(VERSION 3.10)
project(MyClass)

set(CMAKE_CXX_STANDARD 20)

if(NOT MSVC AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-fsanitize=address -g)
    add_link_options(-fsanitize=address)
endif()

add_executable(MyClass MyClass.cpp)
