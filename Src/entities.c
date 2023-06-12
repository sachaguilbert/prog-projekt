#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "entities.h"

void initPlayer(player_t *pla, int32_t x, int32_t y, int32_t dx, int32_t dy){
	pla->posx = x;
	pla->posy = y;
	pla->velx = dx;
	pla->vely = dy;
}
void initAsteroid(astroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy){
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
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style){
	planet->posx = x;
	planet->posy = y;
	planet->style = style;
}

void createBullet(player_t p,bullet_t *b){
	uint8_t speedConst = 2; // Determines the speed, since pacc is always 1

	bullet_t newB;
	newB.posx = p.posx;
	newB.posy = p.posy;
	newB.velx = p.accx*speedConst;
	newB.velx = p.accy*speedConst;
	uint16_t j =0;
	while(j<100){
		if(b[j].posx != NULL){
			b[j] = newB;
			return;
		}
		j++;
	}
}
