cmake_minimum_required(VERSION 3.8)
project(MidtermTests)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp OurList.h OurList.cpp)
add_executable(MidtermTests ${SOURCE_FILES})