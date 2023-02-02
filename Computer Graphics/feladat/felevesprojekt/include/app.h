#ifndef APP_H
#define APP_H

#include "camera.h"
#include "scene.h"

#include <SDL2/SDL.h>

#include <stdbool.h>

#define VIEWPORT_RATIO (16.0 / 9.0)

typedef struct App {
    SDL_Window *window;
    SDL_GLContext gl_context;
    SDL_GameController *gGameController;
    int JOYSTICK_DEAD_ZONE;
    int easter_egg_counter;
    int screenshot_counter;
    bool is_running;
    double uptime;
    Camera camera;
    Scene scene;
    Audio audio;
    bool is_collision_on;
} App;

/**
 * Initialize the application.
 */
void init_app(App *app, int width, int height);

/**
 * Initialize the OpenGL context.
 */
void init_opengl();

/**
 * Reshape the window.
 */
void reshape(GLsizei width, GLsizei height);

/**
 * Handle the events of the application.
 */
void handle_app_events(App *app);

/**
 * Update the application.
 */
void update_app(App *app);

/**
 * Render the application.
 */
void render_app(App *app);

/**
 * Destroy the application.
 */
void destroy_app(App *app);

/**
 * Creates a screenshot.
 */
int takeScreenshot(int counter);

#endif /* APP_H */
