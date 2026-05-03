cmake_minimum_required(VERSION 3.10)
project(Calendar)

set(CMAKE_CXX_STANDARD 20)

add_executable(Calendar main.cpp
        Date.cpp
        Date.h
        Calendar.cpp
        Calendar.h)
