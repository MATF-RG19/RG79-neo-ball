#include "../include/keyboard.h"

/*pomeranje loptice*/
float zFront = 0;
float angle = 0;
float zBack = 0;
float xLeft = 0;
float xRight = 0;

/*promenljiva koja oznacava da li se krecemo levo(-1) ili desno(1)*/
int side = 1;

/*indikatori kretanja lopte: ind_lr = levo/desno, ind_fb = napred/nazad*/
int ind_lr = 0;
int ind_fb = 0;

void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {

        case ESC:
            exit(0);
            break;

        case '1':
            glutFullScreen();
            break;
        case 'W':
        case 'w':
            if(!is_blocked_z){
                zFront += 0.07;
                ind_fb = 1;
                ind_lr = 0;
                angle += 2.5;
            } 
            glutPostRedisplay();
            break;
        case 'S':
        case 's':
            zBack += 0.07;
            ind_fb = 1;
            ind_lr = 0;
            angle -=2.5;
            glutPostRedisplay();
            break;
        case 'A':
        case 'a':
            if(!is_blocked_x){
                ind_fb = 0;
                ind_lr = 1;
                xLeft += 0.07;
                side = -1;
                angle += 2.5;
            }
            glutPostRedisplay();
            break;
        case 'D':
        case 'd':
            xRight += 0.07;
            side = 1;
            ind_fb = 0;
            ind_lr = 1;
            angle += 2.5;
            glutPostRedisplay();
            break;
    }

}