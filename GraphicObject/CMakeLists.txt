cmake_minimum_required(VERSION 3.10)
project(GraphicObject)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphicObject GraphicObject.h GraphicObject.cpp Circle.cpp Circle.h main.cpp Object.cpp Object.h Rectangle.cpp Rectangle.h)
