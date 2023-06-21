/*
 * player.c
 *
 *  Created on: 20. jun. 2023
 *      Author: alber
 */
#include "player.h"

// NO NO
void LEDHP(player_t* p){

	if(p->hitpoints >= MAXHP){
		setLED(0,1,0);
	}else if(p->hitpoints < MAXHP && p->hitpoints > 1){
		setLED(1,1,0);
	}else if(p->hitpoints == 1){
		setLED(1,0,0);
	}
}

void update_player_pos(player_t *p)
{

	p->posx += p->velx;
	p->posy += p->vely;
	if((p->velx >> 12) > 0)
	{
		p->velx-= (1 << 11);
	} else if((p->velx >> 12) < 0)
	{
		p->velx+= (1 << 11);
	}
	if((p->vely >> 12) > 0)
	{
			p->vely-= (1 << 11);
	} else if((p->vely >> 12) < 0)
	{
		p->vely+= (1 << 11);
	}
	p->velx = abs(p->velx) < (1 << 12) ? 0 : p->velx;
	p->vely = abs(p->vely) < (1 << 12) ? 0 : p->vely;

	p->posx = p->posx >= (WIN_WIDTH - 5) << 14 ? 6 << 14 : p->posx;
	p->posy = p->posy >= (WIN_HEIGHT - 5) << 14 ? 6 << 14 : p->posy;
	p->posx = p->posx <= 5 << 14 ? (WIN_WIDTH - 6) << 14: p->posx;
	p->posy = p->posy <= 5 << 14 ? (WIN_HEIGHT - 6) << 14 : p->posy;

}
void movement(player_t *p,bullet_t *b){
	uint16_t j1 = ADCRead(1);
	if(j1 >= JoystickHigh){
		p->velx += p->accx;
		p->dir = 0;
	}
	if(j1 <= JoystickLow){
		p->velx -= p->accx;
		p->dir = 4;
	}
	uint16_t j2 = ADCRead(0);
	if(j2 >= JoystickHigh){
		p->vely -= p->accx >> 1;
		p->dir = 2;
	}
	if(j2 <= JoystickLow){
		p->vely += p->accx >> 1;
		p->dir = 6;
	}

	if((j1 >= JoystickHigh) && (j2 >= JoystickHigh)){p->dir = 1;}
	if((j1 >= JoystickHigh) && (j2 <= JoystickLow)){p->dir = 7;}
	if((j1 <= JoystickLow) && (j2 >= JoystickHigh)){p->dir = 3;}
	if((j1 <= JoystickLow) && (j2 <= JoystickLow)){p->dir = 5;}


	uint16_t b1 = ADCRead(3);
	if(b1 >= 4000){
		createBullet(*p,b);
	}


	// Limit
	p->velx = p->velx >= 2 << 14 ? 2 << 14 : p->velx;
	p->vely = p->vely >= 2 << 14 ? 2 << 14 : p->vely;
	p->velx = p->velx <= -2 << 14 ? -2 << 14 : p->velx;
	p->vely = p->vely <= -2 << 14 ? -2 << 14 : p->vely;

}

void initPlayer(player_t *p){
	p->posx = 10 << 14;
	p->posy = 10 << 14;
	p->score = 0;
	p->dir = 0;
	p->velx = 0;
	p->vely = 0;
	p->accx = 1 << 14;
	p->accy = 0;
	p->radius = 4;
	p->hitpoints = 3;
	p->level = 1;
	p->oldLevel = p->level;
	p->dmg = 1;
}
