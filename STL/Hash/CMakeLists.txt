cmake_minimum_required(VERSION 3.28)
project(Hash)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hash main.cpp
        测试map_set_hash/test.cpp
        HashTable.cpp
        HashTable.h)
