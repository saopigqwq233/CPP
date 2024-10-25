cmake_minimum_required(VERSION 3.29)
project(jsondeserialize)

set(CMAKE_CXX_STANDARD 17)

add_executable(jsondeserialize main.cpp
        KJSon.h
        KJSon.cpp)
