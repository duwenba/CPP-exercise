cmake_minimum_required(VERSION 3.27)
project(Queue)

set(CMAKE_CXX_STANDARD 17)
#file(GLOB_RECURSE src ./*.cpp ./*.h *.hpp)

add_executable(${PROJECT_NAME} main.cpp Queue.hpp LinkQueue.hpp CircleQueue.h)
