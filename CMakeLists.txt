cmake_minimum_required(VERSION 3.9)
project(ai_hw3)

set(CMAKE_CXX_STANDARD 11)
configure_file(sampleFile.txt sampleFile.txt COPYONLY)
configure_file(sample30.txt sample30.txt COPYONLY)
configure_file(sample15.txt sample15.txt COPYONLY)
configure_file(sample10.txt sample10.txt COPYONLY)
configure_file(sample80.txt sample80.txt COPYONLY)
add_executable(ai_hw3
        main.cpp
        Makefile Parser.h Parser.cpp NodeType.h Node.h Fringe.h EuclideanFringe.cpp EuclideanFringe.h GridMap.cpp GridMap.h ManhattanFringe.cpp ManhattanFringe.h)
