#include "../include/keyboard.h"
float zFront = 0;
float angle_forw = 0;
float angle_side = 0;
float zBack = 0;
float xLeft = 0;
float xRight = 0;
float yUp = 0;
float yDown = 0;
void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {

        case ESC:
            exit(0);
            break;

        case '1':
            glutFullScreen();
            break;
        case 'W':
        case 'w':
            zFront += 0.07;
            angle_forw += 2.5; 
            glutPostRedisplay();
            break;
        case 'S':
        case 's':
            zBack += 0.07;
            angle_forw -=2.5;
            glutPostRedisplay();
            break;
        case 'A':
        case 'a':
            xLeft += 0.07;
            glutPostRedisplay();
            break;
        case 'D':
        case 'd':
            xRight += 0.07;
            angle_side += 2.5;
            glutPostRedisplay();
            break;
    }

}