#include "../include/texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

GLuint load_texture(char *filename) {
    SDL_Surface *surface;
    GLuint texture_name;
    surface = IMG_Load(filename);

    glGenTextures(1, &texture_name);

    SDL_RWops *rwop;
    rwop = SDL_RWFromFile(filename, "rb");

    GLint format;

    if (IMG_isPNG(rwop)) {
        format = GL_RGBA;
    } else {
        format = GL_RGB;
    }

    glBindTexture(GL_TEXTURE_2D, texture_name);
    glTexImage2D(GL_TEXTURE_2D, 0, format, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE,
                 (Pixel *) (surface->pixels));

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return texture_name;
}