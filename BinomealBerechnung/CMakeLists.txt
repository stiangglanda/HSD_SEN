cmake_minimum_required(VERSION 4.0)
project(BinomealBerechnung)

set(CMAKE_CXX_STANDARD 20)

add_executable(BinomealBerechnung main.cpp
        binom.cpp
        binom.h)
