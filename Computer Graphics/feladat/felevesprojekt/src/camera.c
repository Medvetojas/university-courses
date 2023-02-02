#include "../include/camera.h"
#include "../include/texture.h"

#include <math.h>

void init_camera(Camera *camera) {
    camera->position.x = 0.0;
    camera->position.y = 0.0;
    camera->position.z = 1.510;
    camera->rotation.x = 0.0;
    camera->rotation.y = 0.0;
    camera->rotation.z = 0.0;
    camera->speed.x = 0.0;
    camera->speed.y = 0.0;
    camera->speed.z = 0.0;

    camera->collision[0] = -1.249973;
    camera->collision[1] = -2.130876;
    camera->collision[2] = 1.288146 - camera->collision[0];
    camera->collision[3] = 2.159242 - camera->collision[1];
    camera->collision[4] = 0.774;
    camera->collision[5] = 2.214;
}

void update_camera(Camera *camera, double time) {
    double angle;
    double side_angle;
    float newX, newY, newZ;

    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);

    if (camera->is_collision_on) {
        newX = camera->position.x + cos(angle) * camera->speed.y * time + cos(side_angle) * camera->speed.x * time;
        newY = camera->position.y + sin(angle) * camera->speed.y * time + sin(side_angle) * camera->speed.x * time;
        newZ = camera->position.z + camera->speed.z * time;

        if (camera->collision[0] + COLLISION_PADDING < newX &&
            (camera->collision[0] + camera->collision[2]) - 2 * COLLISION_PADDING > newX) {
            camera->position.x += cos(angle) * camera->speed.y * time;
            camera->position.x += cos(side_angle) * camera->speed.x * time;
        }

        if (camera->collision[1] + COLLISION_PADDING < newY &&
            (camera->collision[1] + camera->collision[3]) - 2 * COLLISION_PADDING > newY) {
            camera->position.y += sin(angle) * camera->speed.y * time;
            camera->position.y += sin(side_angle) * camera->speed.x * time;
        }

        if (camera->collision[4] + COLLISION_PADDING < newZ && camera->collision[5] - COLLISION_PADDING > newZ) {
            camera->position.z += camera->speed.z * time;
        }
    } else {
        camera->position.x += cos(angle) * camera->speed.y * time;
        camera->position.y += sin(angle) * camera->speed.y * time;

        camera->position.x += cos(side_angle) * camera->speed.x * time;
        camera->position.y += sin(side_angle) * camera->speed.x * time;
        camera->position.z += camera->speed.z * time;
    }
}

void set_view(const Camera *camera) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotated(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotated(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslated(-camera->position.x, -camera->position.y, -camera->position.z);
}

void rotate_camera(Camera *camera, double horizontal, double vertical) {
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera *camera, double speed) {
    camera->speed.y = speed;
}

void set_camera_horizontal_speed(Camera *camera, double speed) {
    camera->speed.x = speed;
}

void set_camera_vertical_speed(Camera *camera, double speed) {
    camera->speed.z = speed;
}

void set_camera_collision(Camera *camera, bool is_collision_on) {
    camera->is_collision_on = is_collision_on;
}