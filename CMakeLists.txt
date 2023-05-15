cmake_minimum_required(VERSION 3.24)
project(Zoo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Zoo main.cpp Animal.cpp Animal.h Zoo.cpp Zoo.h)
