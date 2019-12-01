#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <GL/glut.h>
#include <math.h>
#include "timer.h"
#include "lighting.h"

void make_floor(int a);
void add_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
float mult;
void set_mult(float m);
void add_rising_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
void add_moving_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
void add_end_platform(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);

#endif