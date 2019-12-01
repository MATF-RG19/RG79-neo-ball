#include "../include/init.h"
#include <GL/glut.h>

void reshape(int width, int height);

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(800, 500);
    glutInitWindowPosition(350, 180);
    glutCreateWindow("Neo Ball");

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(reshape);
    glutDisplayFunc(on_display);

    glutTimerFunc(10, on_time, 0);

    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);

    lighting();

    glutMainLoop();

    return 0;
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();    
    gluPerspective(45, (float) width / height, 1, 10);
}