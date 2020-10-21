cmake_minimum_required(VERSION 3.17)
project(Collection C)

set(CMAKE_C_STANDARD 11)

add_executable(Collection main.c Collections.h Collections.c Collections.h)