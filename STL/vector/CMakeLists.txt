cmake_minimum_required(VERSION 3.27)
project(vector)

set(CMAKE_CXX_STANDARD 11)

add_executable(vector main.cpp
        vector.cpp
        vector.h)
