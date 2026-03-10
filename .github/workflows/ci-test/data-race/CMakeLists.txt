cmake_minimum_required(VERSION 4.4)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
project(data-race)

set(CMAKE_CXX_MODULE_STD 1)

include(CTest)

add_executable(data-race data-race.cpp)
add_test(data-race data-race)
