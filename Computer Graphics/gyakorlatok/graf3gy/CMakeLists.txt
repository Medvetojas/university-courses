cmake_minimum_required(VERSION 3.21)
project(graf3gy C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_FLAGS "-lmingw32 -lfreeglut -lopengl32 -lglu32")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(graf3gy main.c include/draw.h include/callbacks.h include/ball.h include/game.h include/init.h include/pad.h ball.c callbacks.c draw.c game.c init.c pad.c)
target_link_libraries(graf3gy mingw32)