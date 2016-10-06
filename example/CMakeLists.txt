cmake_minimum_required(VERSION 3.5)
project(LyxTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(../include)

enable_testing()

set(SOURCE_FILES main.cpp Test.cpp Test.hpp)
add_executable(LyxTest ${SOURCE_FILES})

target_link_libraries(LyxTest lyx)