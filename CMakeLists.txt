cmake_minimum_required(VERSION 3.22)
project(catgrep)

set(CMAKE_CXX_STANDARD 20)

add_executable(catgrep main.cpp Arguments.cpp Arguments.h String.h)
