#include "../include/app.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

void init_app(App *app, int width, int height) {
    int error_code;
    int inited_loaders;

    app->is_running = false;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    app->window = SDL_CreateWindow(
            "Babik Szilárd Kristóf - A6NQW1 - Számítógépi grafika féléves feladat",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            SDL_WINDOW_OPENGL);
    if (app->window == NULL) {
        printf("[ERROR] Unable to create the application window!\n");
        return;
    }

    app->gl_context = SDL_GL_CreateContext(app->window);
    if (app->gl_context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    init_opengl();
    reshape(width, height);

    init_camera(&(app->camera));
    init_scene(&(app->scene));

    app->is_running = true;
    app->screenshot_counter = 0;
    app->easter_egg_counter = 0;

}


void init_opengl() {
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    //glEnable(GL_FOG);
    //glEnable(GL_CULL_FACE);
}

void reshape(GLsizei width, GLsizei height) {
    int x, y, w, h;
    double ratio;

    ratio = (double) width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int) ((double) height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    } else {
        w = width;
        h = (int) ((double) width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
            -.08, .08,
            -.06, .06,
            .1, 2000
    );
}

void handle_app_events(App *app) {
    SDL_Event event;
    static bool is_mouse_down = false;
    static int mouse_x = 0;
    static int mouse_y = 0;
    static int controller_x = 0;
    static int controller_y = 0;
    int x, y;


    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_CONTROLLERBUTTONDOWN:
                switch (event.cbutton.button) {
                    case SDL_CONTROLLER_BUTTON_START:
                        app->is_running = false;
                        break;
                    case SDL_CONTROLLER_BUTTON_BACK:
                        if (app->easter_egg_counter == 5) {
                            app->scene.is_easter_egg_visible = true;
                            break;
                        }
                        if (!app->scene.is_help_visible) {
                            app->scene.is_help_visible = true;
                            app->easter_egg_counter++;
                        } else {
                            app->scene.is_help_visible = false;
                        }
                        break;
                }
            case SDL_CONTROLLERAXISMOTION:
                if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
                    if (event.caxis.value < -(app->JOYSTICK_DEAD_ZONE)) {
                        controller_x = -1;
                    } else if (event.caxis.value > (app->JOYSTICK_DEAD_ZONE)) {
                        controller_x = 1;
                    } else {
                        controller_x = 0;
                    }
                } else if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
                    if (event.caxis.value < -(app->JOYSTICK_DEAD_ZONE)) {
                        controller_y = -1;
                    } else if (event.jaxis.value > (app->JOYSTICK_DEAD_ZONE)) {
                        controller_y = 1;
                    } else {
                        controller_y = 0;
                    }
                }

                rotate_camera(&(app->camera), -controller_x, -controller_y);

                break;
                /*
            case SDL_JOYAXISMOTION:
                if (event.jaxis.which == 0) {
                    if (event.jaxis.axis == 0) {
                        if (event.jaxis.value < -(app->JOYSTICK_DEAD_ZONE)) {
                            controller_x = -1;
                            printf("Controller X: %d, Value: %d\n", controller_x, event.jaxis.value);
                        } else if (event.jaxis.value > (app->JOYSTICK_DEAD_ZONE)) {
                            controller_x = 1;
                            printf("Controller X: %d, Value: %d\n", controller_x, event.jaxis.value);
                        } else {
                            controller_x = 0;
                        }
                    } else if (event.jaxis.axis == 1) {
                        if (event.jaxis.value < -(app->JOYSTICK_DEAD_ZONE)) {
                            controller_y = -1;
                            printf("Controller Y: %d, Value: %d\n", controller_y, event.jaxis.value);
                        } else if (event.jaxis.value > (app->JOYSTICK_DEAD_ZONE)) {
                            controller_y = 1;
                            printf("Controller Y: %d, Value: %d\n", controller_y, event.jaxis.value);
                        } else {
                            controller_y = 0;
                        }
                    }

                    rotate_camera(&(app->camera), -controller_x, -controller_y);
                }
                 */
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE:
                        app->is_running = false;
                        break;
                    case SDL_SCANCODE_W:
                        set_camera_speed(&(app->camera), 4);
                        break;
                    case SDL_SCANCODE_S:
                        set_camera_speed(&(app->camera), -4);
                        break;
                    case SDL_SCANCODE_A:
                        set_camera_horizontal_speed(&(app->camera), 4);
                        break;
                    case SDL_SCANCODE_D:
                        set_camera_horizontal_speed(&(app->camera), -4);
                        break;
                    case SDL_SCANCODE_SPACE:
                        set_camera_vertical_speed(&(app->camera), 4);
                        break;
                    case SDL_SCANCODE_LCTRL:
                        set_camera_vertical_speed(&(app->camera), -4);
                        break;
                    case SDL_SCANCODE_F1:
                        SDL_SetWindowBrightness(app->window, SDL_GetWindowBrightness(app->window) + 0.1);
                        break;
                    case SDL_SCANCODE_F2:
                        SDL_SetWindowBrightness(app->window, SDL_GetWindowBrightness(app->window) - 0.1);
                        break;
                    case SDL_SCANCODE_TAB:
                        if (app->easter_egg_counter == 5) {
                            app->scene.is_easter_egg_visible = true;
                            break;
                        }
                        if (!app->scene.is_help_visible) {
                            app->scene.is_help_visible = true;
                            app->easter_egg_counter++;
                        } else {
                            app->scene.is_help_visible = false;
                        }
                        break;
                    case SDL_SCANCODE_H:
                        printf("Camera X: %f\n", app->camera.position.x);
                        printf("Camera Y: %f\n", app->camera.position.y);
                        printf("Camera Z: %f\n", app->camera.position.z);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                    case SDL_SCANCODE_S:
                        set_camera_speed(&(app->camera), 0);
                        break;
                    case SDL_SCANCODE_A:
                    case SDL_SCANCODE_D:
                        set_camera_horizontal_speed(&(app->camera), 0);
                        break;
                    case SDL_SCANCODE_SPACE:
                    case SDL_SCANCODE_LCTRL:
                        set_camera_vertical_speed(&(app->camera), 0);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                is_mouse_down = true;
                break;
            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&x, &y);
                if (is_mouse_down) {
                    rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
                }
                mouse_x = x;
                mouse_y = y;
                break;
            case SDL_MOUSEBUTTONUP:
                is_mouse_down = false;
                break;
            case SDL_QUIT:
                app->is_running = false;
                break;
            default:
                break;
        }
    }
}


void update_app(App *app) {
    double current_time;
    double elapsed_time;

    current_time = (double) SDL_GetTicks() / 1000;
    elapsed_time = current_time - app->uptime;
    app->uptime = current_time;

    update_camera(&(app->camera), elapsed_time);
    update_scene(&(app->scene), elapsed_time);
}

void render_app(App *app) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&(app->camera));
    render_scene(&(app->scene));
    glPopMatrix();

    if (app->scene.is_help_visible) {
        if (app->scene.is_easter_egg_visible) {
            show_easter_egg(app->scene.easter_egg_texture);
        } else {
            show_help(app->scene.help_texture);
        }
    }

    SDL_GL_SwapWindow(app->window);
}

void destroy_app(App *app) {
    if (app->gl_context != NULL) {
        SDL_GL_DeleteContext(app->gl_context);
    }

    if (app->window != NULL) {
        SDL_DestroyWindow(app->window);
    }

    SDL_Quit();
}