#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <GL/glut.h>
#include <math.h>
#include "timer.h"
#include "lighting.h"
#include "image.h"

void make_floor();
void add_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
float mult;
void set_mult(float m);
void add_rising_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
void add_rising_platforms2(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
void add_moving_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);
void add_end_platform(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ);

void set_textures(void);
void make_sky(void);

float x_plat;
float y_plat1;
float y_plat2;

#endif