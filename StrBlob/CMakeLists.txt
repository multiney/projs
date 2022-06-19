cmake_minimum_required(VERSION 3.0)
project(StrBlob)
add_definitions(-Wall -g)
add_executable(${PROJECT_NAME} main.cpp impl.cpp)
