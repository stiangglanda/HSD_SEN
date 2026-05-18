cmake_minimum_required(VERSION 3.10)
project(STLFunctors)

set(CMAKE_CXX_STANDARD 20)

add_executable(STLFunctors STLFunctors.cpp Fraction.h Fraction.cpp)
