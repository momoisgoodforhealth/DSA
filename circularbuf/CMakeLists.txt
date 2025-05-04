cmake_minimum_required(VERSION 3.10.0)
project(circularbuf VERSION 0.1.0 LANGUAGES C CXX)

add_executable(circularbuf main.cpp)

include(CTest)
enable_testing()

