#include "../include/scene.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>

void init_scene(Scene *scene) {

    load_scene_models(scene);
    load_scene_textures(scene);

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

}

void load_scene_models(Scene *scene) {
    load_model(&(scene->ground), "../assets/models/terrain.obj");
    //load_model(&(scene->cube), "../assets/models/cube.obj");
    load_model(&(scene->house), "../assets/models/house.obj");
    load_model(&(scene->duck), "../assets/models/duck.obj");
}

void load_scene_textures(Scene *scene) {
    scene->ground_texture = load_texture("../assets/textures/tex.jpg");
    //scene->cube_texture = load_texture("../assets/textures/grass.png");
    scene->house_texture = load_texture("../assets/textures/house.jpg");
    scene->duck_texture = load_texture("../assets/textures/duck.jpg");

    scene->help_texture = load_texture("../assets/textures/help.jpg");
    scene->easter_egg_texture = load_texture("../assets/textures/easter_egg.jpg");
}

void load_skybox(Scene scene) {
    glDisable(GL_LIGHTING);

    //glBindTexture(GL_TEXTURE_2D, scene.skybox_texture);

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

    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    glColor4f(0.5, 0.5, 0.5, 1.0);

    glVertex3f(0.0,0.0,10.0);
    glVertex3f(0.0,0.0,11.0);
    glVertex3f(0.0,1.0,11.0);
    glVertex3f(0.0,1.0,10.0);

    glEnd();

    glPopMatrix();
}

void load_lighting(Scene scene) {
    GLfloat fogColor[] = {211, 211, 211, 1};
    glHint(GL_FOG_HINT, GL_NICEST);
    glFogfv(GL_FOG_COLOR, fogColor);
    glFogi(GL_FOG_MODE, GL_EXP2);
    glFogf(GL_FOG_DENSITY, 0.014f);

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

void update_scene(Scene *scene, double time) {
    scene->angle += 50 * time;
    //printf("%f\n", scene->angle); //debug purposes
}

void render_scene(const Scene *scene) {
    load_lighting(*scene);
    set_material(&(scene->base_material));

    //load_skybox(*scene);
    load_map(*scene);
    //load_environment(*scene);

}

void show_help(GLuint help_texture) {
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
}

void show_easter_egg(GLuint easter_egg_texture) {
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

}