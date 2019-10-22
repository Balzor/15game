cmake_minimum_required(VERSION 3.14)
project(15game)

set(CMAKE_CXX_STANDARD 14)

add_executable(15game
        main.cpp BSTree.cpp BSTree.h)

set_target_properties(15game PROPERTIES LINK_FLAGS /STACK:1000000000)