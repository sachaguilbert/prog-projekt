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


void drawGameStart(){
	uint8_t p1[2] = {1,1};
	uint8_t p2[2] = {156,144};

	gameWindow(p1,p2,1);
	player_t p;
	p.posx = 10;
	p.posy = 10;
	drawPlayer(p);

}

void drawPlayer(player_t p){

	gotoxy(p.posx,p.posy);
	printf("%c",219);
	gotoxy(p.posx+1,p.posy);
	printf("%c",219);
	gotoxy(p.posx+2,p.posy);
	printf("%c",219);

	gotoxy(p.posx,p.posy-1);
	printf("%c",220);

	gotoxy(p.posx,p.posy+1);
	printf("%c",223);
}

void drawBullet(bullet_t p){}


