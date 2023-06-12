/*
 * Graphics.c
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include <stdio.h>
#include "stdint.h"
#include "ansi.h"
#include "entities.h"
#include <math.h>
#include "math_st.h"
#define velfactor 0.1




void drawGameStart(player_t p){
	uint8_t p1[2] = {1,1};
	uint8_t p2[2] = {156,144};

	gameWindow(p1,p2,1);
	drawPlayer(p);

}

void deletePlayer(player_t p)
{

	gotoxy(p.posx >> 14,p.posy >> 14);
	printf("%c",32);
	vector_t v1 = {1 << 14,0 << 14};
	rotateVector(&v1,p.dir);
	gotoxy((p.posx+v1.x) >> 14,(p.posy+v1.y) >> 14);
	printf("%c",32);
	vector_t v2 = {2 << 14,0 << 14};
	rotateVector(&v2,p.dir);
	gotoxy((p.posx+v2.x) >> 14,(p.posy+v2.y) >> 14);
	printf("%c",32);
	vector_t v3 = {0 << 14,-1 << 14};
	rotateVector(&v3,p.dir);
	gotoxy((p.posx+v3.x) >> 14,(p.posy+v3.y) >> 14);
	printf("%c",32);
	vector_t v4 = {0 << 14,1 << 14};
	rotateVector(&v4,p.dir);
	gotoxy((p.posx + v4.x),(p.posy+v4.y));
	printf("%c",32);
}

void drawPlayer(player_t p){


	gotoxy(p.posx >> 14,p.posy >> 14);
	printf("%c",219);
	vector_t v1 = {1 << 14,0 << 14};
	rotateVector(&v1,p.dir);
	gotoxy((p.posx+v1.x) >> 14,(p.posy+v1.y) >> 14);
	printf("%c",219);
	vector_t v2 = {2 << 14,0 << 14};
	rotateVector(&v2,p.dir);
	gotoxy((p.posx+v2.x) >> 14,(p.posy+v2.y) >> 14);
	printf("%c",219);
	vector_t v3 = {0 << 14,-1 << 14};
	rotateVector(&v3,p.dir);
	gotoxy((p.posx+v3.x) >> 14,(p.posy+v3.y) >> 14);
	printf("%c",220);
	vector_t v4 = {0 << 14,1 << 14};
	rotateVector(&v4,p.dir);
	gotoxy((p.posx + v4.x),(p.posy+v4.y));
	printf("%c",223);
}


void drawBullets(bullet_t p[]){
	uint16_t size = sizeof(p)/sizeof(p[0]);
	for(uint16_t i =0; i<size;i++){
		if(p[i].posx == NULL){
		gotoxy(p[0].posx,p[0].posy);
		printf("%c","*");
		}
	}
}


