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
#define velfactor 0.1




void drawGameStart(player_t p){
	uint8_t p1[2] = {1,1};
	uint8_t p2[2] = {156,144};

	gameWindow(p1,p2,1);
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


void drawBullets(bullet_t *p){
	for(uint16_t i =0; i<100;i++){
		if(p[i].damagevalue != 0){
			 // Haram removal service
		 	 gotoxy((p[i].posx-p[i].velx*0.5)/pow(2,14),(p[i].posy-p[i].vely*0.5)/pow(2,14));
		 	 printf("%c",32);

		 	 // New draw
			 gotoxy(p[i].posx/pow(2,14),p[i].posy/pow(2,14));
			 printf("%c",'*');
		}

	}
}

void drawAstroids(astroid_t *a){

	for(uint8_t i = 0; i<100;i++){
		if(a[i].hitpoints != 0){
			switch(a[i].style){
				case 1:
					gotoxy(a[i].posx>>14,a[i].posy>>14);
					printf("%c",219);
					gotoxy(1,i+1);
					printf("%i",a[i].posx);
					break;
				case 2:
					break;
				}
		}
	}
}

