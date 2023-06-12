/*
 * entities.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_




typedef struct{
	uint32_t posx,posy;
	int32_t velx,vely,accx,accy;
	int16_t dir;
	uint8_t style,weapon;
	uint16_t hitpoints;
}player_t;

typedef struct{
	uint32_t posx,posy;
	int32_t velx, vely, accx, accy;
	uint8_t style;
	uint16_t hitpoints;
}astroid_t;

typedef struct{
	uint32_t posx,posy;
	int32_t velx,vely,accx,accy;
	uint16_t damagevalue;
}bullet_t;


#endif /* ENTITIES_H_ */
