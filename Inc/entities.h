/*
 * entities.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_


#include "math_st.h"

typedef struct{
	int32_t posx,posy;
	int32_t velx,vely,accx,accy;
	int16_t dir;
	int16_t oldDir;
	vector_t oldPos;
	uint8_t style,weapon;
	uint16_t hitpoints;
	uint8_t mass;
	uint8_t radius;
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
//PLANET
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style);
void planetRandom(planet_t *pla);
// PLAYER
player_t initPlayer(int32_t x, int32_t y);

// ASTEROID
void initAsteroid(astroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy);
void astroidRandom(astroid_t *a);
void updateAsteroid(astroid_t *p);
void astroidOUB(astroid_t *a);

// Bullet
bullet_t initBullet();
void createBullet(player_t p,bullet_t *b);
void updateBullets(bullet_t *p);
void bulletCollisions(bullet_t *b,astroid_t *a,uint32_t *score);
void bulletOUB(bullet_t *b);;


#endif /* ENTITIES_H_ */
