cmake_minimum_required(VERSION 3.27)
project(Tables)

set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories("./")

file(GLOB_RECURSE SOURCES
        "Tables/*.cpp"
        "Readers/*.cpp"
)


add_executable(Tables ${SOURCES} main.cpp)
