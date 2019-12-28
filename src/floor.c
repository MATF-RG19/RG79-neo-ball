#include "../include/floor.h"

#define FILENAME0 "./src/sky.bmp"
#define FILENAME1 "./src/floor.bmp"

GLuint names[2];

float mult = 1.0;

/*promenljiva koja opisuje kretanje platforme desno-levo*/
float x_plat = 0;

/*promenljive koje opsuju kretanje podizucih/spustajucih platformi*/
float y_plat1 = 0;
float y_plat2 = 0;

void set_mult(float m)
{
    mult = m;
}

/*inicijalizacija tekstura*/
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
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_read(image, FILENAME1);

    glBindTexture(GL_TEXTURE_2D, names[1]);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);

    glBindTexture(GL_TEXTURE_2D, 0);

    image_done(image);
}

/*postavljanje neba*/
void make_sky(void)
{
    glBindTexture(GL_TEXTURE_2D, names[0]);
    glBegin(GL_QUADS);
       glNormal3f(0, 0, 1);

        glTexCoord2f(0, 20);
        glVertex3f(-60, 60, z_curr-6);

        glTexCoord2f(0, 0);
        glVertex3f(-60, -10, z_curr-6);

        glTexCoord2f(20, 20);
        glVertex3f(60, 60, z_curr-6);

        glTexCoord2f(20, 0);
        glVertex3f(60, -10, z_curr-6);
    glEnd();
    glBindTexture(GL_TEXTURE_2D,0);
    

}

/*postavljanje poda*/
void make_floor()
{
    glBindTexture(GL_TEXTURE_2D, names[1]);
    glBegin(GL_QUADS);
        glNormal3f(0, 1, 0);

        glTexCoord2f(0, 35);
        glVertex3f(-30, 0, -80);

        glTexCoord2f(0, 0);
        glVertex3f(-60, 0, 60);

        glTexCoord2f(10, 35);
        glVertex3f(30, 0, -80);

        glTexCoord2f(20, 0);
        glVertex3f(60, 0, 60);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
}

/*f-ja za dodavanje staticnih platformi*/
void add_platforms(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}

/*f-je za dodavanje pomerajucih platformi*/
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

/*dodavanje ciljne platforme*/
void add_end_platform(float x, float y, float z, int size, float scaleX, float scaleY, float scaleZ)
{
    glPushMatrix();
        glTranslatef(x, y, z);
        end_platform_lighting();
        glScalef(scaleX, scaleY, scaleZ);
        glutSolidCube(size);
    glPopMatrix();
}