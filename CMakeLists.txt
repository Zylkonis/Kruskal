cmake_minimum_required(VERSION 3.29)
project(Kruskal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Kruskal main.cpp
        Edge.h
        Graph.cpp
        Kruskal.h
        List.h
        Map.h
        Matrix.h
        Pair.h
)
