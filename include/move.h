#ifndef _MOVE_H_
#define _MOVE_H_

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "floor.h"
#include "lighting.h"
#include "keyboard.h"
#include "display.h"
#include "timer.h"

void check_movement(void);
void ball_movements(void);
int platform_no;
float y_up;
float x_moved;

int is_blocked_z;
int is_blocked_x;

#endif