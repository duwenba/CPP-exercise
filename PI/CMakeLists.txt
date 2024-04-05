cmake_minimum_required(VERSION 3.19)
project(pi)


#set(CMAKE_CXX_STANDARD 11)

include_directories(./)

file(GLOB_RECURSE SOURCES
        "token/*.cpp"
        "lexer/*.cpp"
        "configor/*.hpp"
        "ast/*.cpp"
        "parser/*.cpp"
)

add_executable(tokens ${SOURCES} tokens.cpp)
add_executable(ast ${SOURCES} ast.cpp)
