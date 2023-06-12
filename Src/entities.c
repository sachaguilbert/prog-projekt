/*
 * entities.c
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "entities.h"








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



