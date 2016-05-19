cmake_minimum_required(VERSION 3.5)
project(KataCalc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp BinaryCalc.cpp BinaryCalc.h)
add_executable(KataCalc ${SOURCE_FILES})