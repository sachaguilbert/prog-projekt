/*
 * entities.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_



typedef struct{
	uint16_t pos[2],vel[2],acc[2];
	uint8_t style,weapon;
	uint16_t hitpoints;
}player_t;

typedef struct{
	uint16_t pos[2],vel[2],acc[2];
	uint8_t style;
	uint16_t hitpoints;
}astroid_t;

typedef struct{
	uint16_t pos[2],vel[2],acc[2];
	uint16_t damagevalue;
}bullet_t;


#endif /* ENTITIES_H_ */
