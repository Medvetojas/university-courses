cmake_minimum_required(VERSION 3.21)
project(felevesfeladat C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_FLAGS "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj2 -lopengl32 -lm -Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
find_package(OpenGL REQUIRED)

add_executable(felevesfeladat src/main.c src/app.c src/camera.c src/scene.c src/texture.c src/utils.c include/app.h include/camera.h include/scene.h include/texture.h include/utils.h)
target_link_libraries(felevesfeladat mingw32 SDL2main SDL2 SDL2_Image SDL2_Mixer OBJ ${OPENGL_LIBRARIES})