cmake_minimum_required(VERSION 3.10)
project(ArithExpr_codeframe)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArithExpr_codeframe ArithExpr.cpp scanner.h
        parser.h
        parser.cpp)
