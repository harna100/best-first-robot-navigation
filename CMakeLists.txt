cmake_minimum_required(VERSION 3.9)
project(ai_hw3)

set(CMAKE_CXX_STANDARD 11)
configure_file(sampleFile.txt sampleFile.txt COPYONLY)
add_executable(ai_hw3
        main.cpp
        Makefile Parser.h Parser.cpp NodeType.h Node.h Fringe.h EuclideanFringe.cpp EuclideanFringe.h GridMap.cpp GridMap.h ManhattanFringe.cpp ManhattanFringe.h)
