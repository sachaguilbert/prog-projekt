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



typedef struct{
	uint16_t posx,posy,velx,vely,accx,accy;
	uint16_t dir;
	uint8_t style,weapon;
	uint16_t hitpoints;
}player_t;

typedef struct{
	uint16_t posx,posy,velx,vely,accx,accy;
	uint8_t style;
	uint16_t hitpoints;
}astroid_t;

typedef struct{
	uint16_t posx,posy,velx,vely,accx,accy;
	uint16_t damagevalue;
}bullet_t;

