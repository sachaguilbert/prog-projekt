#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "ansi.h"
#include "entities.h"
#include "graphics.h"
#include "math_st.h"
#include "globalTimer.h"
#include "menu.h"
//#include "LCD.h"
//#include "ADC.h"
#include "io.h"
#include "gravity.h"
#include "game.h"


int main(void){
	srand(7);
	gameInit();
	while(1){
		// Planet Init
		planet_t pla[NB_PLANETS];
		planetRandom(pla,NB_PLANETS);
		mainMenu();
		// Bullet Init
		bullet_t bullets[100];
		initBullets(bullets,100);
		// Asteroid Init
		asteroid_t asteroids[100];
		for(int i = 0; i < 100; i++){
			asteroids[i].hitpoints = 0;
		}
		// Player init
		player_t p;
		initPlayer(&p);

		drawGameStart(p);
		uint8_t i = 0;
		uint8_t subTick = 0;
		uint8_t gameon = 1;
		while(gameon){
			bossKey();
			if(globalTick > 0){

				switch(subTick){
				case 0:
					movement(&p,bullets);
					if(i == 100){ // Asteroid spawns every 100' tick
						asteroidRandom(asteroids,p);
						i=0;
					}
					subTick++;
					break;
				case 1:
					updatePlayer(&p);
					updateBullets(bullets,pla);
					updateAsteroid(asteroids);
					bulletCollisions(bullets,asteroids,&p);
					playerCollision(&p, asteroids);
					gameon = gameOver(&p);
					subTick++;
					break;
				case 2:
					if (announcTick >= 500)
					{
						announcTick = 0;
						clearAnnouncement();
					}
					subTick++;
					drawAsteroids(asteroids);
					break;
				case 3:
					drawBullets(bullets);
					drawPlanets(pla,sizeof(pla)/sizeof(pla[0]));
					updateLevel(&p);
					subTick=0;
					break;
				}
				LEDHP(&p);
				lcd_scoreboard(p);
				i++;
				announcTick++;
				globalTick = 0;
			}

		}
	}
}
