#ifndef _KEYBOARD_H
#define _KEYBOARD_H_

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "move.h"

#define ESC 27
float zFront;
float angle_forw;
float angle_side;
float zBack;
float xLeft;
float xRight;
float yUp;
float yDown;
void on_keyboard(unsigned char key, int x, int y);

#endif

