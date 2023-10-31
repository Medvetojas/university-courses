cmake_minimum_required(VERSION 3.24)
project(01_hello C)

set(CMAKE_C_STANDARD 11)
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

add_executable(01_hello main.c)
target_include_directories (01_hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (01_hello ${OpenCL_LIBRARY})