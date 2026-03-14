cmake_minimum_required(VERSION 3.10)
project(KeywordCounter)

set(CMAKE_CXX_STANDARD 20)

add_executable(KeywordCounter main.cpp scanner.h parser.h parser.cpp)
