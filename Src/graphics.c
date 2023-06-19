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
#include "graphics.h"
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
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)-2);
	printf("       ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)-1);
	printf("       ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14));
	printf("       ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)+1);
	printf("       ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)+2);
	printf("       ");
}




void drawPlayer(player_t p,uint8_t init,vector_t *v){
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)-2);
	printf("  ###  ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)-1);
	printf(" #---# ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14));
	printf("#|+0+|#");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)+1);
	printf(" #---# ");
	gotoxy((p.posx >> 14)-3, (p.posy >> 14)+2);
	printf("  ###  ");
	drawRedPixel(p);
}
vector_t redPixelPos(player_t p)
{
	vector_t v = {3 << 14, 0 << 14};
	rotateVector(&v,p.dir-p.oldDir);
	vector_t pixelPos = {v.x + p.posx, v.y + p.posy};
	return pixelPos;
}
void bitShift(vector_t *v)
{
	v->x = v->x << 14;
	v->y = v->y << 14;
}


void drawRedPixel(player_t p)
{
	switch(p.dir)
	{
	case 0:
		gotoxy((p.posx >> 14)+3, (p.posy >> 14));
		break;
	case 1:
		gotoxy((p.posx >> 14)+2, (p.posy >> 14)-1);
		break;
	case 2:
		gotoxy((p.posx >> 14)+1, (p.posy >> 14)-2);
		break;
	case 3:
		gotoxy((p.posx >> 14), (p.posy >> 14)-2);
		break;
	case 4:
		gotoxy((p.posx >> 14)-1, (p.posy >> 14)-2);
		break;
	case 5:
		gotoxy((p.posx >> 14)-2, (p.posy >> 14)-1);
		break;
	case 6:
		gotoxy((p.posx >> 14)-3, (p.posy >> 14));
		break;
	case 7:
		gotoxy((p.posx >> 14)-2, (p.posy >> 14)+1);
		break;
	case 8:
		gotoxy((p.posx >> 14)-1, (p.posy >> 14)+2);
		break;
	case 9:
		gotoxy((p.posx >> 14), (p.posy >> 14)+2);
		break;
	case 10:
		gotoxy((p.posx >> 14)+1, (p.posy >> 14)+2);
		break;
	case 11:
		gotoxy((p.posx >> 14)+2, (p.posy >> 14)+1);
		break;
	}
	fgcolor(1);
	printf("#");
	fgcolor(15);
}


void drawBullets(bullet_t *p){
	// Draws all live bullets, ie dmg >0
	for(uint16_t i =0; i<100;i++){
		if(p[i].damagevalue > 0){
			if((p[i].posx-p[i].velx*0.5)/pow(2,14) != p[i].posx>>14 || (p[i].posy-p[i].vely*0.5)/pow(2,14) != p[i].posy){
				// Haram removal service
				gotoxy((p[i].posx-p[i].velx/2)/pow(2,14),(p[i].posy-p[i].vely/2)/pow(2,14));
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

				// Allows for different styles with different HP values, see astroid init
				switch(a[i].style){
					case 1:
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14));
						printf("%c",32);
						gotoxy(a[i].posx>>14,a[i].posy>>14);
						printf("%c",219);
						break;
					case 2:
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14)-1,(a[i].posy-a[i].vely*0.5)/pow(2,14));
						printf("%c%c%c",32,32,32);
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14)-1);
						printf("%c",32);
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14)+1);
						printf("%c",32);

						gotoxy((a[i].posx>>14)-1,a[i].posy>>14);
						printf("%c%c%c",219,219,219);
						gotoxy(a[i].posx>>14,(a[i].posy>>14)+1);
						printf("%c",223);
						gotoxy(a[i].posx>>14,(a[i].posy>>14)-1);
						printf("%c",220);
						break;
					}
			}
		}
	}
}

void drawPlanets(planet_t *p){
	for(int i=0;i<3;i++){
		gotoxy(p[i].posx>>14,p[i].posy>>14);
		printf(" ####O# ");
		gotoxy(p[i].posx>>14,(p[i].posy>>14)+1);
		printf("#O######");
		gotoxy(p[i].posx>>14,(p[i].posy>>14)+2);
		printf("###O####");
		gotoxy(p[i].posx>>14,(p[i].posy>>14)+3);
		printf(" ###### ");
	}
}
