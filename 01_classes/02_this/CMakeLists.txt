cmake_minimum_required(VERSION 3.10)
project(this)

set(CMAKE_CXX_STANDARD 20)

add_executable(this this.cpp employee.h demangle.h)
