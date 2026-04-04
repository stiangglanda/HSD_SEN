cmake_minimum_required(VERSION 3.10)
project(DateClass)

set(CMAKE_CXX_STANDARD 20)

add_executable(DateClass main.cpp
        Date.cpp
        Date.h
        Calendar.cpp
        Calendar.h)
