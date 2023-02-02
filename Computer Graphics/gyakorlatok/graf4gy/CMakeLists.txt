cmake_minimum_required(VERSION 3.21)
project(graf4gy C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_FLAGS "-lSDL2 -lSDL2main -lmingw32 -lOpenGL -lopengl32 -lglu32 -Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
find_package(OpenGL REQUIRED)

add_executable(graf4gy main.c include/ball.h include/game.h include/pong.h include/pad.h ball.c game.c pad.c pong.c players.c include/players.h)
target_link_libraries(graf4gy mingw32 SDL2main SDL2 ${OPENGL_LIBRARIES})