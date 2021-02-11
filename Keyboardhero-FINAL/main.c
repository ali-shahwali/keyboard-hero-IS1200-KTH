/* mipslabmain.c

   This file written 2020 by Ali Shahwali and Emil Währme
   

   For copyright and licensing, see file COPYING */

#include <stdint.h>   
#include <pic32mx.h>  
#include "header.h"  
int score = 0;
int highscore_easy = 0;
int highscore_hard = 0;
int highscore_medium = 0;
int rand = 0;
int hitZone = 0;
int lives = 3;

/* cursor */
uint8_t cursx = 120;
uint8_t cursy = 25;

int main(void) 
{
    setupOS();
    setupPorts();
    setupSPI();
	display_init();
	/* the game */
	while(1)
	{
		title_screen();
		display_clear();
		menu();
		display_clear();
		keyboardHero();
		display_clear();
		leaderboard();
		display_clear();
	}
	return 0;
}
