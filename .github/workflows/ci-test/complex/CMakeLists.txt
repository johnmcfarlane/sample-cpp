cmake_minimum_required(VERSION 4.3)
project(complex)

include(CTest)

add_executable(complex complex.cpp)
add_test(complex complex)
