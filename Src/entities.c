#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "entities.h"
#include "ansi.h"
#define velfactor 0.5


void initPlayer(player_t *pla, uint32_t x, uint32_t y, uint32_t dx, uint32_t dy){
	pla->posx = x;
	pla->posy = y;
	pla->velx = dx;
	pla->vely = dy;
}
void initAsteroid(astroid_t *ast, uint32_t x, uint32_t y, uint32_t dx, uint32_t dy){
	ast->posx = x;
	ast->posy = y;
	ast->velx = dx;
	ast->vely = dy;
	ast->style = 1;
	if(ast->style == 1){
		ast->hitpoints = 10;
	}else if(ast->style == 2){
		ast->hitpoints = 20;
	}else{
		ast->hitpoints = 30;
	}
}

void createBullet(player_t p,bullet_t *b){
	uint8_t speedConst = 2; // Determines the speed, since pacc is always 1

	bullet_t newB;
	newB.posx = p.posx;
	newB.posy = p.posy;
	newB.velx = p.accx*speedConst;
	newB.vely = p.accy*speedConst;
	newB.accx = 0;
	newB.accy = 0;
	newB.damagevalue = 1;
	uint16_t j =0;
	while(j<100){
		if(b[j].damagevalue == 0){
			b[j] = newB;
			return;
		}
		j++;
	}
}

void updateBullets(bullet_t *p){
	for(uint8_t i = 0;i<100;i++){

		// move bullet if its initialised, ie dmg not 0
		if(p[i].damagevalue != 0){
			p[i].posx += p[i].velx * velfactor;
			p[i].posy += p[i].vely * velfactor;
		}
	}

}
