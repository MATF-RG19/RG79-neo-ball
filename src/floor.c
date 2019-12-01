#include "../include/floor.h"
float mult = 1.0;

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
        glTranslatef(x, y+sin(elevate/50.0f)*mult, z);
        platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}
void add_moving_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        glTranslatef(x+3*sin(elevate/80.0f), y, z);
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