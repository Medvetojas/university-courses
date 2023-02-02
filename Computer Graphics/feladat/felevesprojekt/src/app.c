#include "../include/app.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
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

    int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
    inited_loaders = IMG_Init(img_flags);
    if (inited_loaders == 0) {
        printf("[ERROR] IMG initialization error: %s\n", IMG_GetError());
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("[ERROR] Mixer initialization error: %s\n", Mix_GetError());
        return;
    }

    app->gl_context = SDL_GL_CreateContext(app->window);
    if (app->gl_context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    //Check for controller
    if (SDL_IsGameController(0) < 1) {
        printf("No game controller connected! Controller support disabled for this session.\n");
        app->gGameController = NULL;
        app->JOYSTICK_DEAD_ZONE = 0;
    } else {
        //Load controller support
        app->gGameController = SDL_GameControllerOpen(0);
        app->JOYSTICK_DEAD_ZONE = 8000;
        if (app->gGameController == NULL) {
            printf("[ERROR]: Unable to open game controller: %s\n", SDL_GetError());
        }
    }

    init_opengl();
    reshape(width, height);
    init_camera(&(app->camera));
    init_scene(&(app->scene), &(app->audio));

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
    glEnable(GL_CULL_FACE);
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
                    case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
                        SDL_SetWindowBrightness(app->window, SDL_GetWindowBrightness(app->window) - 0.1);
                        break;
                    case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
                        SDL_SetWindowBrightness(app->window, SDL_GetWindowBrightness(app->window) + 0.1);
                        break;
                    case SDL_CONTROLLER_BUTTON_GUIDE:
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
                    case SDL_CONTROLLER_BUTTON_LEFTSTICK:
                        if (!app->is_collision_on) {
                            app->is_collision_on = true;
                            set_camera_collision(&(app->camera), app->is_collision_on);
                        } else {
                            app->is_collision_on = false;
                            set_camera_collision(&(app->camera), app->is_collision_on);
                        }
                        break;
                    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic((app->audio.gMusic[0]), -1);
                        } else {
                            Mix_HaltMusic();
                            Mix_PlayMusic((app->audio.gMusic[0]), -1);
                        }
                        break;
                    case SDL_CONTROLLER_BUTTON_DPAD_UP:
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic((app->audio.gMusic[1]), -1);
                        } else {
                            Mix_HaltMusic();
                            Mix_PlayMusic((app->audio.gMusic[1]), -1);
                        }
                        break;
                    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic((app->audio.gMusic[2]), -1);
                        } else {
                            Mix_HaltMusic();
                            Mix_PlayMusic((app->audio.gMusic[2]), -1);
                        }
                        break;
                    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                        printf("Camera X: %f\n", app->camera.position.x);
                        printf("Camera Y: %f\n", app->camera.position.y);
                        printf("Camera Z: %f\n", app->camera.position.z);
                        break;
                    default:
                        break;
                }
            case SDL_CONTROLLERAXISMOTION:
                if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
                    if (event.caxis.value<-(app->JOYSTICK_DEAD_ZONE) || event.caxis.value>(app->JOYSTICK_DEAD_ZONE)) {
                        controller_x = event.caxis.value / 8190;
                    }
                }
                if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTY) {
                    if (event.caxis.value<-(app->JOYSTICK_DEAD_ZONE) || event.caxis.value>(app->JOYSTICK_DEAD_ZONE)) {
                        controller_y = event.caxis.value / 8190;
                    }
                }

                rotate_camera(&(app->camera), -controller_x, -controller_y);
                controller_x = 0;
                controller_y = 0;

                if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTX) {
                    if (event.caxis.value<-(app->JOYSTICK_DEAD_ZONE) || event.caxis.value>(app->JOYSTICK_DEAD_ZONE)) {
                        set_camera_horizontal_speed(&(app->camera), -event.jaxis.value / 8190.0);
                    } else {
                        set_camera_horizontal_speed(&(app->camera), 0);
                    }
                }

                if (event.caxis.axis == SDL_CONTROLLER_AXIS_RIGHTY) {
                    if (event.caxis.value<-(app->JOYSTICK_DEAD_ZONE) || event.caxis.value>(app->JOYSTICK_DEAD_ZONE)) {
                        set_camera_vertical_speed(&(app->camera), -event.jaxis.value / 8190.0);
                    } else {
                        set_camera_vertical_speed(&(app->camera), 0);
                    }
                }

                break;
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
                    case SDL_SCANCODE_F12:
                        takeScreenshot(app->screenshot_counter);
                        app->screenshot_counter++;
                        break;
                    case SDL_SCANCODE_1:
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic((app->audio.gMusic[0]), -1);
                        } else {
                            Mix_HaltMusic();
                            Mix_PlayMusic((app->audio.gMusic[0]), -1);
                        }
                        break;
                    case SDL_SCANCODE_2:
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic((app->audio.gMusic[1]), -1);
                        } else {
                            Mix_HaltMusic();
                            Mix_PlayMusic((app->audio.gMusic[1]), -1);
                        }
                        break;
                    case SDL_SCANCODE_3:
                        if (Mix_PlayingMusic() == 0) {
                            Mix_PlayMusic((app->audio.gMusic[2]), -1);
                        } else {
                            Mix_HaltMusic();
                            Mix_PlayMusic((app->audio.gMusic[2]), -1);
                        }
                        break;
                    case SDL_SCANCODE_H:
                        printf("Camera X: %f\n", app->camera.position.x);
                        printf("Camera Y: %f\n", app->camera.position.y);
                        printf("Camera Z: %f\n", app->camera.position.z);
                        break;
                    case SDL_SCANCODE_P:
                        if (!app->is_collision_on) {
                            app->is_collision_on = true;
                            set_camera_collision(&(app->camera), app->is_collision_on);
                        } else {
                            app->is_collision_on = false;
                            set_camera_collision(&(app->camera), app->is_collision_on);
                        }
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
    update_scene(&(app->scene), elapsed_time, &(app->camera));
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

    Mix_Quit();
    IMG_Quit();
    SDL_GameControllerClose(app->gGameController);
    app->gGameController = NULL;
    SDL_Quit();
}

SDL_Surface *flipSurface(SDL_Surface *surface) {
    int current_line, pitch;
    SDL_Surface *fliped_surface = SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                       surface->w, surface->h,
                                                       surface->format->BitsPerPixel,
                                                       surface->format->Rmask,
                                                       surface->format->Gmask,
                                                       surface->format->Bmask,
                                                       surface->format->Amask);

    SDL_LockSurface(surface);
    SDL_LockSurface(fliped_surface);

    pitch = surface->pitch;
    for (current_line = 0; current_line < surface->h; current_line++) {
        memcpy(&((unsigned char *) fliped_surface->pixels)[current_line * pitch],
               &((unsigned char *) surface->pixels)[(surface->h - 1 -
                                                     current_line) * pitch],
               pitch);
    }

    SDL_UnlockSurface(fliped_surface);
    SDL_UnlockSurface(surface);
    return fliped_surface;
}

int takeScreenshot(int count) {
    GLint viewport[4];
    Uint32 rmask, gmask, bmask, amask;
    SDL_Surface *picture, *finalpicture;

    glGetIntegerv(GL_VIEWPORT, viewport);

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

    picture = SDL_CreateRGBSurface(SDL_SWSURFACE, viewport[2], viewport[3], 32, rmask, gmask, bmask, amask);
    SDL_LockSurface(picture);
    glReadPixels(viewport[0], viewport[1], viewport[2], viewport[3], GL_RGBA,
                 GL_UNSIGNED_BYTE, picture->pixels);
    SDL_UnlockSurface(picture);

    finalpicture = flipSurface(picture);

    char finalfilename[] = "ScreenshotN";
    finalfilename[10] = count + '0';

    if (SDL_SaveBMP(finalpicture, finalfilename)) {
        return -1;
    }

    SDL_FreeSurface(finalpicture);
    SDL_FreeSurface(picture);

    return 0;
}