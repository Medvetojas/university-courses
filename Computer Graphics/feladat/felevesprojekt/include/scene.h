#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>
#include <SDL2/SDL_mixer.h>

typedef struct Scene {
    Model grass;
    Model house;
    Model duck;
    Model ground;
    Model barrel;
    Model power_box;
    Model sofa;
    Model coffee_table;
    Model hare;
    Material base_material;
    GLuint grass_texture;
    GLuint house_texture;
    GLuint duck_texture;
    GLuint skybox_texture;
    GLuint ground_texture;
    GLuint barrel_texture;
    GLuint power_box_texture;
    GLuint sofa_texture;
    GLuint coffee_table_texture;
    GLuint hare_texture;
    GLuint help_texture;
    GLuint easter_egg_texture;
    float angle;
    bool is_help_visible;
    bool is_easter_egg_visible;
    vec3 duck_position;
} Scene;

typedef struct Audio {
    Mix_Music *gMusic[3];
} Audio;

/**
 * Initialize the scene by loading models and textures.
 */
void init_scene(Scene *scene, Audio *audio);

/**
 * Initializes the models.
 */

void load_scene_models(Scene *scene);

/**
 * Initializes the textures used by the models.
 */

void load_scene_textures(Scene *scene);

/**
 * Initializes the sounds.
 */
void load_scene_sounds(Audio *audio);

/**
 * Load the skybox.
 */
void load_skybox(Scene scene);

/**
 * Load the base map.
 */
void load_map(Scene scene);

/**
 * Load the buildings.
 */
void load_environment(Scene scene);

/**
 * Set the lighting of the scene.
 */
void load_lighting(Scene scene);

/**
 * Set the current base material.
 */
void set_material(const Material *material);

/**
 * Update the scene.
 */
void update_scene(Scene *scene, double time, Camera *camera);

/**
 * Render the scene objects.
 */
void render_scene(const Scene *scene);

#endif /* SCENE_H */
