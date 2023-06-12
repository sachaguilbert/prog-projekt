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
#define velfactor 0.1


void drawGameStart(){
	uint8_t p1[2] = {1,1};
	uint8_t p2[2] = {156,144};

	gameWindow(p1,p2,1);
	player_t p;
	p.posx = 10 << 14;
	p.posy = 10 << 14;
	drawPlayer(p);

}

void drawPlayer(player_t p){

//******Deletes previous position*******
	gotoxy((p.posx-p.velx*velfactor)/pow(2,14),(p.posy-p.vely*velfactor)/pow(2,14));
	printf("%c",32);
	gotoxy((p.posx-p.velx*velfactor)/pow(2,14)+1,(p.posy-p.vely*velfactor)/pow(2,14));
	printf("%c",32);
	gotoxy((p.posx-p.velx*velfactor)/pow(2,14)+2,(p.posy-p.vely*velfactor)/pow(2,14));
	printf("%c",32);

	gotoxy((p.posx-p.velx*velfactor)/pow(2,14),(p.posy-p.vely*velfactor)/pow(2,14)-1);
	printf("%c",32);

	gotoxy((p.posx-p.velx*velfactor)/pow(2,14),(p.posy-p.vely*velfactor)/pow(2,14)+1);
	printf("%c",32);

//******Deletes previous position*******


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

<<<<<<< HEAD

void drawBullet(bullet_t p){}
=======
void drawBullets(bullet_t p[]){
	uint16_t size = sizeof(p)/sizeof(p[0]);
	for(uint16_t i =0; i<size;i++){
		if(p[i] != null){
		gotoxy(p[0].posx,p[0].posy);
		printf("%c","*");
		}
	}
}
>>>>>>> e6410ba4f08fb78a7cc94fa7d5e6212d6a4a8511


