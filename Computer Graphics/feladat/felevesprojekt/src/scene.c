#include "../include/scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_scene(Scene *scene, Audio *audio) {

    load_scene_models(scene);
    load_scene_textures(scene);
    load_scene_sounds(audio);

    scene->base_material.ambient.red = 1.0f;
    scene->base_material.ambient.green = 1.0f;
    scene->base_material.ambient.blue = 1.0f;

    scene->base_material.diffuse.red = 1.0f;
    scene->base_material.diffuse.green = 1.0f;
    scene->base_material.diffuse.blue = 1.0f;

    scene->base_material.specular.red = 1.0f;
    scene->base_material.specular.green = 1.0f;
    scene->base_material.specular.blue = 1.0f;
    scene->base_material.shininess = 1.0f;

    scene->angle = 0;
    scene->is_help_visible = false;
    scene->is_easter_egg_visible = false;
    scene->duck_position.x = 10;
    scene->duck_position.y = 10;
    scene->duck_position.z = 15;

}

void load_scene_models(Scene *scene) {
    load_model(&(scene->ground), "../assets/models/terrain.obj");
    load_model(&(scene->grass), "../assets/models/grass.obj");
    load_model(&(scene->house), "../assets/models/house.obj");
    load_model(&(scene->duck), "../assets/models/duck.obj");
    load_model(&(scene->barrel), "../assets/models/barrel.obj");
    load_model(&(scene->power_box), "../assets/models/power_box.obj");
    load_model(&(scene->sofa), "../assets/models/sofa.obj");
    load_model(&(scene->coffee_table), "../assets/models/coffee_table.obj");
    load_model(&(scene->hare), "../assets/models/hare.obj");
}

void load_scene_textures(Scene *scene) {
    scene->skybox_texture = load_texture("../assets/textures/skybox.jpg");
    scene->ground_texture = load_texture("../assets/textures/tex.jpg");
    scene->grass_texture = load_texture("../assets/textures/grass.png");
    scene->house_texture = load_texture("../assets/textures/house.jpg");
    scene->duck_texture = load_texture("../assets/textures/duck.jpg");
    scene->barrel_texture = load_texture("../assets/textures/standard_barrel.jpg");
    scene->power_box_texture = load_texture("../assets/textures/power_box.jpg");
    scene->sofa_texture = load_texture("../assets/textures/sofa.jpg");
    scene->coffee_table_texture = load_texture("../assets/textures/coffee_table.jpg");
    scene->hare_texture = load_texture("../assets/textures/hare.jpg");

    scene->help_texture = load_texture("../assets/textures/help.jpg");
    scene->easter_egg_texture = load_texture("../assets/textures/easter_egg.jpg");
}

void load_scene_sounds(Audio *audio) {
    audio->gMusic[0] = Mix_LoadMUS("../assets/audio/base_music.mp3");
    if (audio->gMusic[0] == NULL) {
        printf("Failed to load music1! SDL_mixer Error: %s\n", Mix_GetError());
    }

    audio->gMusic[1] = Mix_LoadMUS("../assets/audio/base_music_2.mp3");
    if (audio->gMusic[1] == NULL) {
        printf("Failed to load music2! SDL_mixer Error: %s\n", Mix_GetError());
    }

    audio->gMusic[2] = Mix_LoadMUS("../assets/audio/base_music_3.mp3");
    if (audio->gMusic[2] == NULL) {
        printf("Failed to load music3! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

void load_skybox(Scene scene) {
    glDisable(GL_LIGHTING);

    glBindTexture(GL_TEXTURE_2D, scene.skybox_texture);

    double theta, phi1, phi2;
    double x1, y1, z1;
    double x2, y2, z2;
    double u, v1, v2;
    int n_slices, n_stacks;
    double radius;
    int i, k;
    n_slices = 15;
    n_stacks = 15;
    radius = 70;

    glPushMatrix();

    glScaled(radius, radius, radius);

    glColor3f(1, 1, 1);

    glBegin(GL_TRIANGLE_STRIP);

    for (i = 0; i < n_stacks; ++i) {
        v1 = (double) i / n_stacks;
        v2 = (double) (i + 1) / n_stacks;
        phi1 = v1 * M_PI / 2.0;
        phi2 = v2 * M_PI / 2.0;
        for (k = 0; k <= n_slices; ++k) {
            u = (double) k / n_slices;
            theta = u * 2.0 * M_PI;
            x1 = cos(theta) * cos(phi1);
            y1 = sin(theta) * cos(phi1);
            z1 = sin(phi1) - 0.25;
            x2 = cos(theta) * cos(phi2);
            y2 = sin(theta) * cos(phi2);
            z2 = sin(phi2) - 0.25;
            glTexCoord2d(u, 1.0 - v1);
            glVertex3d(x1, y1, z1);
            glTexCoord2d(u, 1.0 - v2);
            glVertex3d(x2, y2, z2);
        }
    }

    glEnd();

    glPopMatrix();

    glEnable(GL_LIGHTING);
}

void load_map(Scene scene) {
    glPushMatrix();

    glBindTexture(GL_TEXTURE_2D, scene.duck_texture);
    glTranslatef(0, 0, 15);
    glScaled(0.25, 0.25, 0.25);
    glRotated(scene.angle, -0.0, 0.0, -10.0);
    glTranslated(10.0, 50.0, 0.0);
    draw_model(&(scene.duck));

    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene.ground_texture);
    glTranslatef(-30, -30, -3.5f);
    glRotatef(90, 1, 0, 0);
    draw_model(&(scene.ground));
    glPopMatrix();
}

void load_environment(Scene scene) {


    glPushMatrix();

    glTranslated(0, 0, 0.6);
    glScaled(0.05, 0.05, 0.05);
    glRotatef(90, 1, 0, 0);
    glBindTexture(GL_TEXTURE_2D, scene.house_texture);
    glDisable(GL_CULL_FACE); // workaround for the house texture
    draw_model(&(scene.house));
    glEnable(GL_CULL_FACE);

    glPopMatrix();

    glPushMatrix();

    glTranslated(-1.00, -2.3, 1);
    glScaled(1.5, 1.5, 1.5);
    glRotated(180, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, scene.power_box_texture);
    draw_model(&(scene.power_box));

    glPopMatrix();

    glScaled(0.5, 0.5, 0.5);
    glTranslated(2.3, 0, 1.2);
    glRotated(90, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, scene.sofa_texture);
    draw_model(&(scene.sofa));

    glPushMatrix();

    glPushMatrix();

    glScaled(0.5, 0.55, 0.5);
    glTranslated(10.7, 1, 1.5);
    glBindTexture(GL_TEXTURE_2D, scene.barrel_texture);
    draw_model(&(scene.barrel));

    glPopMatrix();

    glPushMatrix();

    glScaled(1.5, 1.5, 1.5);
    glTranslated(0, 1.52, 0.1);
    glBindTexture(GL_TEXTURE_2D, scene.coffee_table_texture);
    draw_model(&(scene.coffee_table));

    glPopMatrix();
    glPushMatrix();

    glTranslated(43, 0.7, -2);
    glRotated(180, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, scene.hare_texture);
    draw_model(&(scene.hare));

    glPopMatrix();

    glPushMatrix();

    glEnable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glTranslated(9, -1, 0.6);
    glRotated(90, 0, 1, 0);
    glRotated(90, 0, 0, 1);
    glBindTexture(GL_TEXTURE_2D, scene.grass_texture);
    draw_model(&(scene.grass));

    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_BLEND);
    glPopMatrix();
}

void load_lighting(Scene scene) {
    GLfloat light0_ambient[] = {0.1f, 0.1f, 0.1f, 1.0f};
    GLfloat light0_diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat light0_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

    GLfloat light1_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat light1_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light1_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light1_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat spot1_direction[] = {0.0f, -1.0f, -1.0f};

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

    glPushMatrix();

    glTranslated(-2, -5, 50);
    glRotatef(scene.angle, 0, 0, 1);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot1_direction);

    glPopMatrix();


} //RGB for light and XYZ for position

void set_material(const Material *material) {
    float ambient_material_color[] = {
            material->ambient.red,
            material->ambient.green,
            material->ambient.blue
    };

    float diffuse_material_color[] = {
            material->diffuse.red,
            material->diffuse.green,
            material->diffuse.blue
    };

    float specular_material_color[] = {
            material->specular.red,
            material->specular.green,
            material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene *scene, double time, Camera *camera) {
    if (scene->angle > 360) {
        scene->angle = 0;
    } else {
        scene->angle += 50 * time;
    }
}

void render_scene(const Scene *scene) {
    load_lighting(*scene);
    set_material(&(scene->base_material));

    load_skybox(*scene);
    load_map(*scene);
    load_environment(*scene);

}

void show_help(GLuint help_texture) {
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, help_texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -3);
    glEnd();


    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

}

void show_easter_egg(GLuint easter_egg_texture) {
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, easter_egg_texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3d(-2, 1.5, -3);
    glTexCoord2f(1, 0);
    glVertex3d(2, 1.5, -3);
    glTexCoord2f(1, 1);
    glVertex3d(2, -1.5, -3);
    glTexCoord2f(0, 1);
    glVertex3d(-2, -1.5, -3);
    glEnd();


    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

}