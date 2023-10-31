cmake_minimum_required(VERSION 3.24)
project(fft C)

set(CMAKE_C_STANDARD 11)
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})
link_directories(${OpenCL_LIBRARY})

add_executable(fft main.c kernel_loader.c)
target_include_directories(fft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(fft ${OpenCL_LIBRARY})
