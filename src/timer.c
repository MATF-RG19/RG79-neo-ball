#include "../include/timer.h"

float elevate = 0;
void on_time(int val)
{
    if(val != 0)
        return;
    
    elevate++;

    glutPostRedisplay();

    check_movement();
    ball_movements();

    glutTimerFunc(10, on_time, 0);
}