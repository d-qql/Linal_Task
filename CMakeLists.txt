cmake_minimum_required(VERSION 3.10)
project(LinalIteration)

set(CMAKE_CXX_STANDARD 11)

add_executable(LinalIteration main.cpp Matrix.cpp Matrix.h Vector.cpp Vector.h)