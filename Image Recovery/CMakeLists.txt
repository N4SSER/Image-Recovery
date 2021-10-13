cmake_minimum_required(VERSION 3.20)
project(Image_Recovery)

set(CMAKE_CXX_STANDARD 23)

add_executable(Image_Recovery main.cpp Gen.cpp Gen.h Solution.cpp Solution.h)
