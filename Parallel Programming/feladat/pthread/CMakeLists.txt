cmake_minimum_required(VERSION 3.21)
project(lol2 C)

set(CMAKE_C_STANDARD 99)

add_executable(lol2 main.c)
target_link_libraries(lol2 pthread)