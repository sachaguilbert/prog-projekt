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
	p.pos[0] = 10;
	p.pos[1] = 10;
	drawPlayer(p);

}

void drawPlayer(player_t p){
	uint8_t x = p.pos[0];
	uint8_t y = p.pos[1];
	gotoxy(x,y);
	printf("%c",219);
	gotoxy(x+1,y);
	printf("%c",219);
	gotoxy(x+2,y);
	printf("%c",219);

	gotoxy(x,y-1);
	printf("%c",220);

	gotoxy(x,y+1);
	printf("%c",223);



}

