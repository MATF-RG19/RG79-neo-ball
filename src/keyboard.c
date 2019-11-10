#include "../include/keyboard.h"

void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {

        case ESC:
            exit(0);
            break;

        case '1':
            glutFullScreen();
            break;
    }

}