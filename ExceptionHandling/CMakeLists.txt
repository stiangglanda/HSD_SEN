cmake_minimum_required(VERSION 3.10)
project(ExceptionHandling)

set(CMAKE_CXX_STANDARD 20)

add_executable(ExceptionHandling main.cpp Exceptions.h Exceptions.cpp scanner.h)
