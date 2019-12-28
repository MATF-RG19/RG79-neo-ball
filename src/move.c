#include "../include/move.h"

/*oznaka platforme*/
int platform_no = 1;

float y_up = 0;

float x_moved = 0;

int is_blocked_z = 0;
int is_blocked_x = 0;

/*indikator pada*/
int fall = 0;


void fall_func(void)
{
    if(y_curr < -3){
        printf("Game over\n");
        exit(EXIT_FAILURE);
    }

    fall = 1;
}

/*brute force provera kretanja i dozvoljenih pozicija loptice*/
void check_movement(void)
{
    if(z_curr >1.2 && z_curr < 3 && x_curr > -0.8 && x_curr < 0.8)
    {
        platform_no = 1;

        /*loptica ne bi smela da predje na platformu
         dok ona nema istu y-koordinatu kao loptica */
        if(y_plat1 > -0.48 && z_curr < 1.4)
            is_blocked_z = 1;
        else 
            is_blocked_z = 0;
        
    }
    else if(z_curr <= 1.2 && z_curr > -1 && x_curr > -1.12 && x_curr < 1.12)
    {
        platform_no = 2;

        /*loptica ne bi smela da predje na sledecu platformu
         dok platforma nema dovoljnu y-koordinatu za prelaz */
        if(y_curr+0.29 < 2 && z_curr < -0.8)
            is_blocked_z = 1;
        else
            is_blocked_z = 0;
        
    }

    else if(z_curr <=-1 && z_curr > -1.8 && x_curr > -2.8 && x_curr < 2.8)
    {
        platform_no = 3;
    }

    else if(z_curr <= -1 && z_curr > -3.6 && x_curr <= -2.8 && x_curr > -3.8)
    {
        platform_no = 4;
    }

    else if(z_curr <= -3.6 && z_curr > -4.5 &&((platform_no == 4 && x_plat < -2 && x_curr+1 > x_plat)
        || (platform_no == 6 && x_curr-1 < x_plat && x_plat > 1.9)))
    {
        platform_no = 5;
    }

    else if (platform_no == 4 && x_plat >-2 && z_curr <= -3.6)
    {
        fall_func();
    }

    else if(platform_no == 5 && fabs(x_plat-x_curr) > 1){
        fall_func();
    }

    else if(z_curr <= -4.5 && z_curr > -8.5 && x_curr > 2.9 && x_curr < 4)
    {
        platform_no = 6;
    }

    else if(z_curr <= -7.6 && z_curr > -8.5 && x_curr <= 2.9 && x_curr >= -0.8)
    {
        platform_no = 7;

        /*loptica ne bi smela da predje na platformu
         dok ona nema istu y-koordinatu kao loptica */
        if(y_plat2 < 1.85 && y_plat2 > 1.36 && x_curr < -0.3)
            is_blocked_x = 1;
        else
            is_blocked_x = 0;
    }

    else if(z_curr <= -7.6 && z_curr > -8.5 && x_curr > -1.4 && x_curr<=-0.6 && y_plat2 < 1.4)
    {
        platform_no = 8;

        /*loptica ne bi smela da predje na sledecu platformu
         dok platforma nema dovoljnu y-koordinatu za prelaz */
        if(y_curr < 2.9 && z_curr <= -8.3)
            is_blocked_z = 1;
        else
            is_blocked_z = 0;
    }

    else if(platform_no == 8 && (x_curr <= -1.4 || z_curr > -7.6))
    {
        fall_func();
    }

    else if(platform_no == 7 && (x_curr<=-0.6 || z_curr > -7.6 || z_curr <=-8.5))
    {
        fall_func();
    }

    else if(z_curr <= -8.5 && z_curr > -10 && x_curr > -1.5 && x_curr < -0.5)
    {
        platform_no = 9;
    }

    else if (platform_no == 9 && z_curr > -8.5)
    {
        platform_no = 8;
    }
    

    else if(z_curr <= -10  && x_curr > -1.5 && x_curr < -0.5)
    {
        platform_no = 10;
        printf("You won!\n");
        exit(EXIT_SUCCESS);
    }

    else if(platform_no!=5 && platform_no !=7 && platform_no != 8)
    {
        fall_func();
    }
    
}

/*loptica se krece gore/dole ili levo/desno zajedno sa platformom*/
void ball_movements(void)
{
    switch(platform_no)
    {
        case 2:
            y_up = sin(elevate/50.0f)*mult;
        break;

        case 5:
            x_moved = 6*fabs(sin(elevate/180.0f));
            break;
        case 8:
            y_up = sin(elevate/50.0f)*mult;
        break;
    }
}

