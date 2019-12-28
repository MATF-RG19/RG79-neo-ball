#include "../include/lighting.h"

/*podesavanje boje loptice*/
void set_ball_lighting(void)
{
    GLfloat ambient_coef[] = { 0.9765, 0.2392, 0.2627, 1 };

    GLfloat diffuse_coef[] = { 1, 0.6902, 0 };

    GLfloat specular_coef[] = { 0.9765, 0.2392, 0.2627};

    int shininess = 5;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coef);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coef);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coef);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

/*postavljanje osvetljenja*/
void lighting(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat light_pos[] = { 0.25, 1.1, 1.4, 0 };
    GLfloat ambient  [] = {.01, .01, .01, 1};
	GLfloat diffuse  [] = {1,1,1,1};
	GLfloat specular [] = {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
}

/*postavljanje boje za platforme*/
void platform_lighting(void)
{
    GLfloat ambient_coef[] = { 0.3098, 0.2588, 0.7098, 1 };

    GLfloat diffuse_coef[] = { 0.1961 ,0.1647 ,0.4549, 1 };

    GLfloat specular_coef[] = {  0.3098, 0.2588, 0.7098, 1};

    int shininess = 20;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coef);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coef);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_coef);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

/*postavljanje boje za ciljnu platformu*/
void end_platform_lighting(void)
{

    GLfloat ambient_coef[] = { 0.8431 ,0.4549, 0.6549, 1 };

    GLfloat diffuse_coef[] = { 0.7843, 0.2549, 5255, 1 };

    GLfloat specular_coef[] = { 0.8431 ,0.4549, 0.6549, 1};

    int shininess = 20;
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_coef);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_coef);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_coef);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}