cmake_minimum_required(VERSION 3.10)
project(RandomNumberLaeufeTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(RandomNumberLaeufeTest main.cpp
        RandomGen.cpp
        RandomGen.h)
