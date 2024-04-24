cmake_minimum_required(VERSION 3.27)
project(BTree)

## cashed option
set(CMAKE_GENERATOR "Ninja" CACHE STRING "Generator" FORCE)



set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_COMPILER "g++")

file(GLOB_RECURSE SOURCES *.cpp *.hpp)

add_executable(main main.cpp)
