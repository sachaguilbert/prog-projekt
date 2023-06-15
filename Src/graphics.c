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
	if((p.oldPos.x >> 12) != (redPixelPos(p).x >> 12) || (p.oldPos.y >> 12) != (redPixelPos(p).y >> 12))
	{
		for(int i = -4; i <= 4; i++)
		{
			for(int j = -4; j <= 4; j++)
			{
				vector_t v = {i << 14,j << 14};
				drawPlayerPixel(p,&v,32);
			}
		}
	}

}




void drawPlayer(player_t p,uint8_t init,vector_t *v){

	if(init)
	{
		v[0].x = 0;
		v[0].y = 0;

		v[1].x = 1;
		v[1].y = 0;

		v[2].x = 2;
		v[2].y = 0;

		v[3].x = 3;
		v[3].y = 0;

		v[4].x = -1;
		v[4].y = 0;

		v[5].x = -2;
		v[5].y = 0;

		v[6].x = -3;
		v[6].y = 0;

		v[7].x = 0;
		v[7].y = -1;

		v[8].x = 1;
		v[8].y = -1;

		v[9].x = 2;
		v[9].y = -1;

		v[10].x = -1;
		v[10].y = -1;

		v[11].x = -2;
		v[11].y = -1;

		v[12].x = 0;
		v[12].y = 1;

		v[13].x = 1;
		v[13].y = 1;

		v[14].x = 2;
		v[14].y = 1;

		v[15].x = -1;
		v[15].y = 1;

		v[16].x = -2;
		v[16].y = 1;

		v[17].x = 0;
		v[17].y = -2;

		v[18].x = -1;
		v[18].y = -2;

		v[19].x = 1;
		v[19].y = -2;

		v[20].x = 0;
		v[20].y = 2;

		v[21].x = 1;
		v[21].y = 2;

		v[22].x = -1;
		v[22].y = 2;
		for(int i = 0; i < 23; i++)
		{
			bitShift(&v[i]);
		}
	}



	drawPlayerPixel(p,&v[0],48);
	drawPlayerPixel(p,&v[1],43);
	drawPlayerPixel(p,&v[2],124);
	fgcolor(1);
	drawPlayerPixel(p,&v[3],35);
	fgcolor(15);
	drawPlayerPixel(p,&v[4],43);
	drawPlayerPixel(p,&v[5],124);
	drawPlayerPixel(p,&v[6],35);

	drawPlayerPixel(p,&v[7],45);
	drawPlayerPixel(p,&v[8],45);
	drawPlayerPixel(p,&v[9],35);
	drawPlayerPixel(p,&v[10],45);
	drawPlayerPixel(p,&v[11],35);

	drawPlayerPixel(p,&v[12],45);
	drawPlayerPixel(p,&v[13],45);
	drawPlayerPixel(p,&v[14],35);
	drawPlayerPixel(p,&v[15],45);
	drawPlayerPixel(p,&v[16],35);

	drawPlayerPixel(p,&v[17],35);
	drawPlayerPixel(p,&v[18],35);
	drawPlayerPixel(p,&v[19],35);

	drawPlayerPixel(p,&v[20],35);
	drawPlayerPixel(p,&v[21],35);
	drawPlayerPixel(p,&v[22],35);
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

void drawPlayerPixel(player_t p, vector_t *v, uint8_t ch)
{
	if(p.oldDir != p.dir)
	{
		rotateVector(v,p.dir-p.oldDir);
	}

	int8_t testx = round(v->x/pow(2,14));
	int8_t testy = round(v->y/pow(2,14));
	gotoxy((p.posx >> 14)+testx,(p.posy >> 14)+testy);
	printf("%c",ch);
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
				printf("%c",62);
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
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14));
						printf("%c",32);
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14)+1,(a[i].posy-a[i].vely*0.5)/pow(2,14));
						printf("%c",32);
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14)-1,(a[i].posy-a[i].vely*0.5)/pow(2,14));
						printf("%c",32);
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14)-1);
						printf("%c",32);
						gotoxy((a[i].posx-a[i].velx*0.5)/pow(2,14),(a[i].posy-a[i].vely*0.5)/pow(2,14)+1);
						printf("%c",32);


						gotoxy(a[i].posx>>14,a[i].posy>>14);
						printf("%c",219);
						gotoxy((a[i].posx>>14)+1,a[i].posy>>14);
						printf("%c",219);
						gotoxy((a[i].posx>>14)-1,a[i].posy>>14);
						printf("%c",219);
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
