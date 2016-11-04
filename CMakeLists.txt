cmake_minimum_required(VERSION 3.6)
project(game_of_random)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp game.cpp game.h)
add_executable(game_of_random ${SOURCE_FILES})