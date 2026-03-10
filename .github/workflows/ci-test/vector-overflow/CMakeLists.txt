cmake_minimum_required(VERSION 4.4)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
project(vector-overflow)

set(CMAKE_CXX_MODULE_STD 1)

include(CTest)

add_executable(vector-overflow vector-overflow.cpp)
add_test(vector-overflow vector-overflow)
