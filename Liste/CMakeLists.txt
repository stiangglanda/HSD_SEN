cmake_minimum_required(VERSION 4.1)
project(Liste)

set(CMAKE_CXX_STANDARD 20)

add_executable(Liste ListeMain.cpp
        ListenModul.cpp
        ListenModul.h)
