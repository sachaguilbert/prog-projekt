#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "ansi.h"
#include "entities.h"
#include "graphics.h"
#include "input.h"
#include "math_st.h"
#include "globalTimer.h"


int main(void)
{
	srand(time(NULL));
	bullet_t bullets[100];
	astroid_t astriods[100];

	uart_init(921600);
	clrscr();

	// Bullet Init
	bullet_t bullets[100];
	bullet_t b;
	b.accx =0;
	b.accy =0;
	b.damagevalue =0;
	b.posx =0;
	b.posy =0;
	b.velx =0;
	b.vely =0;
	uint16_t i = 0;
	while(i<100){
		bullets[i]=b;
		i++;
	}
	// Astroid Init
	astroid_t astroids[100];
	astroid_t a;
	a.accx =0;
	a.accy =0;
	a.hitpoints =0;
	a.posx =0;
	a.posy =0;
	a.velx =0;
	a.vely =0;
	a.style =1;
	a.mass =0;
	i = 0;
	while(i<100){
		astroids[i]=a;
		i++;
	}

	// TEST ASTROID
	/*
	astroid_t ast;
	ast.style = 1;
	initAsteroid(&ast,50<<14,10<<14,0,0);
	astroids[0] = ast;*/



	// Player init
	player_t p;
	p.posx = 10 << 14;
	p.posy = 10 << 14;
	p.dir = 0;
	p.velx = 0;
	p.vely = 0;
	p.accx = 1 << 14;
	p.accy = 0;

	drawGameStart(p);


	tim15Setup();
	i = 0;
	while(1){
		if(globalTick){

			if(uart_get_count() > 0)
			{
				update_player_input(&p,bullets);
			} else{

			}

			if(i == 100){
				astroidRandom(astroids);
				i=0;
			}
			//Update
			update_player_pos(&p);
			updateBullets(bullets);
			updateAsteroid(astroids);
			bulletCollisions(bullets,astroids);
			astroidOUB(astroids);
			bulletOUB(bullets);
			// DRAW
			drawBullets(bullets);
			drawAstroids(astroids);
			drawPlayer(p);

			i++;
			globalTick = 0;
			deletePlayer(p);
		}

	}

}
