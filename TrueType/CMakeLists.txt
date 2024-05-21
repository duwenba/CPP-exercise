cmake_minimum_required(VERSION 3.27)
project(Tables)

set(CMAKE_CXX_STANDARD 23)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories("./")

file(GLOB_RECURSE SOURCES
        "Tables/*.cpp"
        "Readers/*.cpp"
)

#find_package(Freetype REQUIRED)
#target_link_libraries(main PRIVATE Freetype::Freetype) # since CMake 3.10

add_executable(Tables ${SOURCES} main.cpp)
