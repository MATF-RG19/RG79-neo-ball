#include "../include/lighting.h"


void set_lighting(void)
{
    GLfloat light_pos[] = { 0.2, 0.8, 1, 0 };

    GLfloat ambient_coef[] = { 1, 35/255.0, 106/255.0, 1 };

    GLfloat diffuse_coef[] = { 0.98039, 0.41961, 0.83137 };

    GLfloat specular_coef[] = { 244/255.0, 174/255.0, 11/255.0};

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coef);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coef);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, specular_coef);
}