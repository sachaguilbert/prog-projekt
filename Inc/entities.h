/*
 * entities.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_




typedef struct{
	int32_t posx,posy;
	int32_t velx,vely,accx,accy;
	int16_t dir;
	uint8_t style,weapon;
	uint16_t hitpoints;
	uint8_t mass;
}player_t;

typedef struct{
	int32_t posx,posy;
	int32_t velx, vely, accx, accy;
	uint8_t style;
	uint16_t hitpoints;
	uint8_t mass;
}astroid_t;

typedef struct{
	int32_t posx,posy;
	int32_t velx,vely,accx,accy;
	uint16_t damagevalue;
}bullet_t;

typedef struct{
	int32_t posx,posy;
	uint16_t style;
}planet_t;

void initPlayer(player_t *pla, int32_t x, int32_t y, int32_t dx, int32_t dy);
void initAsteroid(astroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy);
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style);

void createBullet(player_t p,bullet_t *b);

#endif /* ENTITIES_H_ */
