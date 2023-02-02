#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#include <stdbool.h>
#include <GL/gl.h>

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera {
    vec3 position;
    vec3 rotation;
    vec3 speed;
} Camera;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera *camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera *camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera *camera);

/**
 * Set the horizontal and vertical rotation of the view angle, using an input device.
 */
void rotate_camera(Camera *camera, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera *camera, double speed);

/**
 * Set the speed of horizontal steps.
 */
void set_camera_horizontal_speed(Camera *camera, double speed);

/**
 * Set the speed of vertical steps.
 */
void set_camera_vertical_speed(Camera *camera, double speed);

/**
 * Displays the help picture.
 */
void show_help(GLuint help_texture);

/**
 * Displays the easter egg picture.
 */
void show_easter_egg(GLuint easter_egg_texture);

#endif /* CAMERA_H */
