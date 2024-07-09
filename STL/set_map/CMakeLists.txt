cmake_minimum_required(VERSION 3.28)
project(set_map)

set(CMAKE_CXX_STANDARD 11)

add_executable(set_map
        AVL.cpp
        AVL.h
        RBTree.h
        myset.cpp
        myset.h
        mymap.cpp
        mymap.h)
