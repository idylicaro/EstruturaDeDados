cmake_minimum_required(VERSION 3.15)
project(FilaArranjo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -static-libgcc -static-libstdc++")
add_executable(FilaArranjo main.cpp FilaBackend.h)