cmake_minimum_required(VERSION 3.21)
project(parallel7gy C)

set(CMAKE_C_STANDARD 99)

add_executable(parallel7gy main.c dynamicarray.h linkedlist.h queue.h)
