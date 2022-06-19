cmake_minimum_required(VERSION 3.0)
project(hello)
file(GLOB SRC_FILE *.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILE})
