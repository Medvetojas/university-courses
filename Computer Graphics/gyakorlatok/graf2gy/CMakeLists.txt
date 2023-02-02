cmake_minimum_required(VERSION 3.21)
project(drawline C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_FLAGS "-lSDL2 -lSDL2main -lmingw32")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(drawline main.c)
target_link_libraries(drawline mingw32 SDL2main SDL2)