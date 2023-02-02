cmake_minimum_required(VERSION 3.21)
project(graf5gy C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_FLAGS "-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lobj -lopengl32 -lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
find_package(OpenGL REQUIRED)


add_executable(graf5gy src/main.c src/app.c src/camera.c src/scene.c src/utils.c include/app.h include/camera.h include/scene.h include/utils.h)
target_link_libraries(graf5gy mingw32 SDL2main SDL2 SDL2_Image ${OPENGL_LIBRARIES})