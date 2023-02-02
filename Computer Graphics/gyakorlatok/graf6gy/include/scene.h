#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene { //struct for the displayed scene
    Model cube;
    Model house;
    Model duck;
    Model ground;
    Material base_material;
    //GLuint cube_texture;
    GLuint house_texture;
    GLuint ground_texture;
    GLuint duck_texture;
    GLuint help_texture;
    GLuint easter_egg_texture;
    float angle;
    bool is_help_visible;
    bool is_easter_egg_visible;
} Scene;

/**
 * Initialize the scene by loading models and textures.
 */
void init_scene(Scene *scene);

/**
 * Initializes the models.
 */

void load_scene_models(Scene *scene);

/**
 * Initializes the textures used by the models.
 */

void load_scene_textures(Scene *scene);

/**
 * Load the skybox.
 */
void load_skybox(Scene scene);

/**
 * Load the base map.
 */
void load_map(Scene scene);

/**
 * Load the grass.
 */
void load_grass(Scene scene);

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
void update_scene(Scene *scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene *scene);

#endif /* SCENE_H */
