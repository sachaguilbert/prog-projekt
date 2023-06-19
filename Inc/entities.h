/*
 * entities.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_


#include "math_st.h"
//#include "graphics.h"

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
	uint8_t level;
	uint16_t score;
	uint16_t dmg;
}player_t;

typedef struct{
	int32_t posx[5];
	int32_t posy[5];
	int32_t velx, vely, accx, accy;
	uint8_t style;
	int16_t hitpoints;
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
void planetRandom(planet_t *pla, uint8_t nrOfPla);
void playerCollision(player_t *p, astroid_t *a);
// PLAYER
player_t initPlayer(int32_t x, int32_t y);

// ASTEROID
void initAsteroid(astroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy,player_t p);
void astroidRandom(astroid_t *a,player_t p);
void updateAsteroid(astroid_t *a);
void astroidOUB(astroid_t *a);

// Bullet
bullet_t initBullet();
void createBullet(player_t p,bullet_t *b);
void updateBullets(bullet_t *b);
void bulletCollisions(bullet_t *b,astroid_t *a, player_t *p);
void bulletOUB(bullet_t *b);
void playerCollision(player_t *p, astroid_t *a);

void updateLevels(player_t *p);


#endif /* ENTITIES_H_ */
