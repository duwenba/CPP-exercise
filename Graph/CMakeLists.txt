cmake_minimum_required(VERSION 3.28)
project(Graph)

set(CMAKE_CXX_STANDARD 17)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE GRAPH_SOURCES
        Graph/*.cpp
        ShortestPath/*.cpp
        spaningTree/*.cpp
)

add_executable(Graph graphTest.cpp ${GRAPH_SOURCES})

add_executable(spanningTree spanningTreeTest.cpp ${GRAPH_SOURCES})

add_executable(shortestPath shortestPathTest.cpp ${GRAPH_SOURCES})