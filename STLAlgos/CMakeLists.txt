cmake_minimum_required(VERSION 3.20)
project(STLAlgos)

set(CMAKE_CXX_STANDARD 20)

add_executable(STLAlgos STLAlgos.cpp STLAlgos.h Output.h Output.cpp algos_with_pred.cpp algos.cpp algos_with_adapter.cpp)

