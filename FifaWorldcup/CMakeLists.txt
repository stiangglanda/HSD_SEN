cmake_minimum_required(VERSION 3.10)
project(FifaWorldcup)

set(CMAKE_CXX_STANDARD 20)

add_executable(FifaWorldcup FifaWorldcup.cpp Tournament.h Tournament.cpp scanner.h)
