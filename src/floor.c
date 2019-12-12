#include "../include/floor.h"

#define FILENAME0 "sky.gif"

GLuint names[2];

float mult = 1.0;

float x_plat = 0;
float y_plat1 = 0;
float y_plat2 = 0;

void set_mult(float m)
{
    mult = m;
}

void set_textures(void)
{
    Image * image;

    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);

    image = image_init(0, 0);

    image_read(image, FILENAME0);

    glGenTextures(2, names);

    glBindTexture(GL_TEXTURE_2D, names[0]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);
}

void make_sky(void)
{
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
        //glNormal3f(0, 0, 1);

        glTexCoord2f(0, 0);
        glVertex3f(-1, -1, 0);

        glTexCoord2f(1, 0);
        glVertex3f(1, -1, 0);

        glTexCoord2f(1, 1);
        glVertex3f(1, 1, 0);

        glTexCoord2f(0, 1);
        glVertex3f(-1, 1, 0);
    glEnd();

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