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
	uint8_t mass;
}player_t;

typedef struct{
	uint32_t posx,posy;
	int32_t velx, vely, accx, accy;
	uint8_t style;
	uint16_t hitpoints;
	uint8_t mass;
}astroid_t;

typedef struct{
	uint32_t posx,posy;
	int32_t velx,vely,accx,accy;
	uint16_t damagevalue;
}bullet_t;

// PLAYER
void initPlayer(player_t *pla, uint32_t x, uint32_t y, uint32_t dx, uint32_t dy);

// ASTEROID
void initAsteroid(astroid_t *ast, uint32_t x, uint32_t y, uint32_t dx, uint32_t dy);

// Bullet
void createBullet(player_t p,bullet_t *b);
void updateBullets(bullet_t *p);
void bulletCollisions(bullet_t *b,astroid_t *a);
void bulletOUB(bullet_t *b);;


#endif /* ENTITIES_H_ */
