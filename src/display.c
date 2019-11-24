#include "../include/display.h"

float xPos = 0;
float yPos = 1.2;
float zPos = 2;

void on_display(void)
{
    float rot;
    float rot_side;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0-xLeft+xRight, 3, 5-zFront+zBack,
              0-xLeft+xRight, 1.6, 1-zFront+zBack, 
              0, 1, 0);
    rot = 10*angle_forw;
    rot_side = 10*angle_side;
    glPushMatrix();
        glTranslatef(xPos-xLeft+xRight, yPos, zPos-zFront+zBack);
        glRotatef(rot,1,0,0);
        glRotatef(rot_side,0 ,0,1);
        set_ball_lighting();
        glutSolidSphere(0.25, 50, 30);
    glPopMatrix();;
    glPushMatrix();
        glTranslatef(0, 0.3, 1.5);
        platform_lighting();
        glScalef(1.5, 1, 1);
        glutSolidCube(1);
    glPopMatrix();

    make_floor(20);

    glutSwapBuffers();
}