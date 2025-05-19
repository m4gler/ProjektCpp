cmake_minimum_required(VERSION 3.29)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled2 main.cpp
        market.h
        market.cpp
        chart.h
        chart.cpp
        utils.h
        utils.cpp)
