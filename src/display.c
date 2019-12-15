#include "../include/display.h"

float xPos = 0;
float yPos = 1.2;
float zPos = 2;

float x_curr = 0;
float y_curr = 0;
float z_curr = 0;

float x1_cam = 0;
float y1_cam = 0;
float z1_cam = 0;

float x2_cam = 0;
float y2_cam = 0;
float z2_cam = 0;

void on_display(void)
{
    
    float rot;
    float rot_side;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    x1_cam = 0-xLeft+xRight+x_moved;
    y1_cam = 3+y_up;
    z1_cam = 5-zFront+zBack;

    x2_cam = x1_cam;
    y2_cam = 1.6+y_up;
    z2_cam = 1-zFront+zBack;

    if(platform_no == 1)
    {
        y1_cam = 3;
        y2_cam = 1.6;
    }

    if(platform_no == 8 || platform_no == 9 || platform_no == 10)
    {
        y1_cam += 0.5;
        y2_cam += 0.5;
    }

    gluLookAt(x1_cam, y1_cam, z1_cam,
              x2_cam, y2_cam, z2_cam, 
              0, 1, 0);
    rot = 10*angle_forw;
    rot_side = 10*angle_side;
    glPushMatrix();
        x_curr = xPos-xLeft+xRight+x_moved;
        y_curr = yPos;
        y_curr = y_curr+y_up*0.8;
        if(platform_no == 1)
            y_curr = 1.2;
        if(platform_no == 7)
            y_curr = 1.716626;
        if(platform_no == 8)
        {
            y_curr = y_plat2+0.35;
        }
        if(platform_no == 9 || platform_no ==10)
        {
            y_curr = 3;
        }
        z_curr = zPos-zFront+zBack;

        if(fall)
        {
            y_curr -=0.5 * 9.81 * falling_coef*falling_coef;
        }

        glTranslatef(x_curr, y_curr, z_curr);
        glRotatef(rot,1,0,0);
        glRotatef(rot_side,0 ,0,1);
        set_ball_lighting();
        glutSolidSphere(0.25, 50, 30);
    glPopMatrix();

    add_platforms(0, 0, 1.5, 1, 1.5, 1, 1);
    set_mult(0.5);
    add_rising_platforms(0, 0, 0, 2, 1, 1, 1);

    add_platforms(0, 0, -1.5, 1, 6, 3, 1);
    
    //levi put
    add_platforms(-3.5, 0, -2.25, 1, 1, 3, 2.5);

    add_moving_platforms(-3, 0, -4, 1, 2, 3, 1);
    add_platforms(3.5, 0, -6.5, 1, 1, 3, 4);

    add_platforms(1.5, 0, -8, 1, 4, 3, 1);
    set_mult(0.65);
    add_rising_platforms2(-1, 2, -8, 1, 1, 0.3, 1);

    add_platforms(-1, 0, -9, 1, 1, 5.59, 1);
    add_end_platform(-1, 0, -10, 1, 1, 5.59, 1);

    make_floor();

    //make_sky();

    glutSwapBuffers();
}