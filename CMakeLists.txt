cmake_minimum_required(VERSION 3.31.2)
project(socketChecking)

set(CMAKE_CXX_STANDARD 17)

add_executable(socketChecking main.cpp)
target_link_libraries(socketChecking ws2_32)