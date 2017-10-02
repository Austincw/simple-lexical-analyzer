cmake_minimum_required(VERSION 3.8)
project(COMP322_Project_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Parser.h)
add_executable(COMP322_Project_1 ${SOURCE_FILES} Parser.h)