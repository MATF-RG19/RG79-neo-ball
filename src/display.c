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
    glPopMatrix();
    //make_floor(20);

    add_platforms(0, 0, 1.5, 1, 1.5, 1, 1);
    set_mult(0.5);
    add_rising_platforms(0, -4, 0, 2, 1, 5, 1);

    add_platforms(0, 0, -1.5, 1, 6, 3, 1);
    
    //levi put
    add_platforms(-3.5, 0, -2.25, 1, 1, 3, 2.5);

    add_moving_platforms(0, 0, -4, 1, 2, 3, 1);
    add_platforms(3.5, 0, -6.5, 1, 1, 3, 4);

    add_platforms(1.5, 0, -8, 1, 4, 3, 1);
    set_mult(0.65);
    add_rising_platforms(-1, 2, -8, 1, 1, 0.3, 1);

    add_platforms(-1, 0, -9, 1, 1, 5.59, 1);
    add_end_platform(-1, 0, -10, 1, 1, 5.59, 1);


    glutSwapBuffers();
}