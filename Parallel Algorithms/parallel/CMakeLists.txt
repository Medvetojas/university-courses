cmake_minimum_required(VERSION 3.24)
project(parallel C)

set(CMAKE_C_STANDARD 11)
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

add_executable(parallel main.c)
target_include_directories (parallel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (parallel ${OpenCL_LIBRARY})