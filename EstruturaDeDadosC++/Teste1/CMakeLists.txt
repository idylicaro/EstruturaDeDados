cmake_minimum_required(VERSION 3.15)
project(Teste1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -static-libgcc -static-libstdc++")
add_executable(Teste1 main.cpp Lista_Encadeada.h)