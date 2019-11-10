#include "../include/display.h"

void on_display(void)
{
    set_lighting();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 3, 5,
              0, 1.6, 1, 
              0, 1, 0);

    glutSolidSphere(0.25, 50, 50);
    make_floor(20);

    glutSwapBuffers();
}