#include "../include/floor.h"
float mult = 1.0;

float x_plat = 0;
float y_plat1 = 0;
float y_plat2 = 0;

void set_mult(float m)
{
    mult = m;
}
void make_floor(int a)
{
    glColor3f(0.75, 0.75, 0.75);
    glBegin(GL_LINES);
        for(int i=-2*a;i<=2*a;i++)
        {
            glVertex3f((float)i,-0.4,(float)-a);
            glVertex3f((float)i,-0.4,(float)a);

            glVertex3f((float)-a,-0.4,(float)i);
            glVertex3f((float)a,-0.4,(float)i);
        }
    glEnd();
}

void add_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}

void add_rising_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        y_plat1 = y+sin(elevate/50.0f)*mult;
        glTranslatef(x, y_plat1, z);
        platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}
void add_rising_platforms2(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        y_plat2 = y+sin(elevate/50.0f)*mult;
        glTranslatef(x, y_plat2, z);
        platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}
void add_moving_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        x_plat = x+6*fabs(sin(elevate/180.0f));
        glTranslatef(x_plat, y, z);
        platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}

void add_end_platform(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        end_platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}