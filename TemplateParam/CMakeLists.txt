cmake_minimum_required(VERSION 3.20)
project(TemplateParam)

set(CMAKE_CXX_STANDARD 20)

add_executable(TemplateParam ContainerWrapper.h Fraction.h TemplateParam.cpp)

