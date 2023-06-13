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
	// Draws the gamewindow to exactly fit Alberts screen, maybe change
	uint16_t p1[2] = {1,1};
	uint16_t p2[2] = {156,144};

	gameWindow(p1,p2,1);
}

void deletePlayer(player_t p)
{
	drawPlayerPixel(p,0,0,32);
	drawPlayerPixel(p,1,0,32);
	drawPlayerPixel(p,2,0,32);
	drawPlayerPixel(p,3,0,32);
	drawPlayerPixel(p,-1,0,32);
	drawPlayerPixel(p,-2,0,32);
	drawPlayerPixel(p,-3,0,32);

	drawPlayerPixel(p,0,-1,32);
	drawPlayerPixel(p,1,-1,32);
	drawPlayerPixel(p,2,-1,32);
	drawPlayerPixel(p,-1,-1,32);
	drawPlayerPixel(p,-2,-1,32);

	drawPlayerPixel(p,0,1,32);
	drawPlayerPixel(p,1,1,32);
	drawPlayerPixel(p,2,1,32);
	drawPlayerPixel(p,-1,1,32);
	drawPlayerPixel(p,-2,1,32);

	drawPlayerPixel(p,0,-2,32);
	drawPlayerPixel(p,-1,-2,32);
	drawPlayerPixel(p,1,-2,32);

	drawPlayerPixel(p,0,2,32);
	drawPlayerPixel(p,-1,2,32);
	drawPlayerPixel(p,1,2,32);

}

void drawPlayer(player_t p){
	drawPlayerPixel(p,0,0,48);
	drawPlayerPixel(p,1,0,43);
	drawPlayerPixel(p,2,0,124);
	fgcolor(1);
	drawPlayerPixel(p,3,0,35);
	fgcolor(15);
	drawPlayerPixel(p,-1,0,43);
	drawPlayerPixel(p,-2,0,124);
	drawPlayerPixel(p,-3,0,35);

	drawPlayerPixel(p,0,-1,45);
	drawPlayerPixel(p,1,-1,45);
	drawPlayerPixel(p,2,-1,35);
	drawPlayerPixel(p,-1,-1,45);
	drawPlayerPixel(p,-2,-1,35);

	drawPlayerPixel(p,0,1,45);
	drawPlayerPixel(p,1,1,45);
	drawPlayerPixel(p,2,1,35);
	drawPlayerPixel(p,-1,1,45);
	drawPlayerPixel(p,-2,1,35);

	drawPlayerPixel(p,0,-2,35);
	drawPlayerPixel(p,-1,-2,35);
	drawPlayerPixel(p,1,-2,35);

	drawPlayerPixel(p,0,2,35);
	drawPlayerPixel(p,-1,2,35);
	drawPlayerPixel(p,1,2,35);
}

void drawPlayerPixel(player_t p, int8_t x, int8_t y, uint8_t ch)
{
	vector_t v = {x << 14, y << 14};
	rotateVector(&v,p.dir);
	gotoxy((p.posx >> 14)+round(v.x/pow(2,14)),(p.posy >> 14)+round(v.y/pow(2,14)));
	printf("%c",ch);
}


void drawBullets(bullet_t *p){
	// Draws all live bullets, ie dmg >0
	for(uint16_t i =0; i<100;i++){
		if(p[i].damagevalue > 0){
			if((p[i].posx-p[i].velx*0.5)/pow(2,14) != p[i].posx>>14 || (p[i].posy-p[i].vely*0.5)/pow(2,14) != p[i].posy){
			 // Haram removal service
		 	 gotoxy((p[i].posx-p[i].velx*0.5)/pow(2,14),(p[i].posy-p[i].vely*0.5)/pow(2,14));
		 	 printf("%c",32);

		 	 // New draw
			 gotoxy(p[i].posx>>14,p[i].posy>>14);
			 printf("*");
			}
		}
	}
}

void drawAstroids(astroid_t *a){
	// Draws all astoroids which are alive ie. HP >0
	for(uint8_t i = 0; i<100;i++){
		if(a[i].hitpoints > 0){
			if((a[i].posx-a[i].velx*0.5)/pow(2,14) != a[i].posx>>14 || (a[i].posy-a[i].vely*0.5)/pow(2,14) != a[i].posy){
				 gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14));
				 printf("%c",32);
				// Allows for different styles with different HP values, see astroid init
				switch(a[i].style){
					case 1:
						gotoxy(a[i].posx>>14,a[i].posy>>14);
						printf("%c",219);
						break;
					case 2:
						gotoxy(a[i].posx>>14,a[i].posy>>14);
						printf("%c",219);
						gotoxy(a[i].posx>>14+1,a[i].posy>>14);
						printf("%c",219);
						gotoxy(a[i].posx>>14-1,a[i].posy>>14);
						printf("%c",219);
						gotoxy(a[i].posx>>14,a[i].posy>>14+1);
						printf("%c",219);
						gotoxy(a[i].posx>>14,a[i].posy>>14-1);
						printf("%c",219);
						break;
					}
			}
		}
	}
}

void drawPlanet(planet_t p){
	gotoxy(p.posx>>14,p.posy>>14);
	printf(" ####O# ");
	gotoxy(p.posx>>14,(p.posy>>14)+1);
	printf("#O######");
	gotoxy(p.posx>>14,(p.posy>>14)+2);
	printf("###O####");
	gotoxy(p.posx>>14,(p.posy>>14)+3);
	printf(" ###### ");
}
