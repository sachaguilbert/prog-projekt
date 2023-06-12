/*
 * Graphics.c
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include "entities.h"
#include <math.h>


void drawGameStart(player_t p){
	uint8_t p1[2] = {1,1};
	uint8_t p2[2] = {156,144};

	gameWindow(p1,p2,1);
	drawPlayer(p);

}

void drawPlayer(player_t p){

	gotoxy(p.posx/pow(2,14),p.posy/pow(2,14));
	printf("%c",219);
	gotoxy(p.posx/pow(2,14)+1,p.posy/pow(2,14));
	printf("%c",219);
	gotoxy(p.posx/pow(2,14)+2,p.posy/pow(2,14));
	printf("%c",219);

	gotoxy(p.posx/pow(2,14),p.posy/pow(2,14)-1);
	printf("%c",220);

	gotoxy(p.posx/pow(2,14),p.posy/pow(2,14)+1);
	printf("%c",223);
}

void drawBullet(bullet_t p){}


