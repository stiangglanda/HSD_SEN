cmake_minimum_required(VERSION 3.10)
project(TestData3D)

set(CMAKE_CXX_STANDARD 20)

add_executable(TestData3D RandomGen.cpp RandomGen.h
        TestData.cpp
        TestData.h
        main.cpp scanner.h)
