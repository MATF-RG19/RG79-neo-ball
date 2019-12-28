#ifndef _KEYBOARD_H
#define _KEYBOARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "move.h"

#define ESC 27
float zFront;
float angle;
float zBack;
float xLeft;
float xRight;
int side;
int ind_fb;
int ind_lr;
void on_keyboard(unsigned char key, int x, int y);

#endif

