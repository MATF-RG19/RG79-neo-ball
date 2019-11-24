#include "../include/floor.h"

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