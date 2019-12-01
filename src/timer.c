#include "../include/timer.h"

float elevate = 0;

void on_time(int val)
{
    if(val != 0)
        return;
    
    elevate++;

    glutPostRedisplay();

    glutTimerFunc(10, on_time, 0);
}