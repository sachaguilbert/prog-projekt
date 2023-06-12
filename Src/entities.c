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








void createBullet(player_t p,bullet_t *b[]){
	uint8_t speedConst = 2; // Determines the speed, since pacc is always 1

	bullet_t b;
	b.posx = p.posx;
	b.posy = p.posy;
	b.velx = p.accx*speedConst;
	b.velx = p.accy*speedConst;
	uint16 j =0;
	while(j<100){
		if((*b)[j] != NULL){
			(*b)[j] = b;
			return;
		}
		j++;
	}
}



