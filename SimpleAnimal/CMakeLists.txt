cmake_minimum_required(VERSION 3.10)
project(SimpleAnimal)

set(CMAKE_CXX_STANDARD 20)

add_executable(SimpleAnimal Animal.cpp
        Animal.h Cat.h Cat.cpp Dog.h Dog.cpp Object.h Object.cpp SimpleAnimal.cpp Zoo.h Zoo.cpp)
