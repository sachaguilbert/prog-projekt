#ifndef ENTITIES_H_
#define ENTITIES_H_

/* Includes ------------------------------------------------------------------*/
#include "math_st.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ansi.h"
#include "math.h"
#include "window.h"
#include "math_st.h"

/* Exported types ------------------------------------------------------------*/
typedef struct{
	int32_t posx,posy;
	int32_t velx,vely,accx,accy;
	int16_t dir;
	int16_t hitpoints;
	uint8_t mass;
	uint8_t radius;
	uint8_t level;
	uint8_t oldLevel;
	uint16_t score;
	uint16_t dmg;
}player_t;

typedef struct{
	int32_t posx[5];
	int32_t posy[5];
	int32_t velx, vely;
	uint8_t style;
	int16_t hitpoints;
}asteroid_t;

typedef struct{
	int32_t posx,posy;
	int32_t velx,vely,accx,accy;
	uint16_t damagevalue;
}bullet_t;

typedef struct{
	int32_t posx,posy;
	uint16_t style;
}planet_t;

/* Exported constants ---------------------------------------------------*/
#define velfactor 2

/* Exported functions ------------------------------------------------------- */

//Player
void initPlayer(player_t *p);

//Planets
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style);
void planetRandom(planet_t *pla, uint8_t nrOfPla);
void playerCollision(player_t *p, asteroid_t *a);

//Asteroids
void initAsteroid(asteroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy,player_t p);
void asteroidRandom(asteroid_t *a, player_t p);
void updateAsteroid(asteroid_t *a);
void asteroidOB(asteroid_t *a);
void asteroidDeath(asteroid_t *a);

//Bullets
void createBullet(player_t p,bullet_t *b);
void initBullets(bullet_t *b,uint8_t size);
void updateBullets(bullet_t *b, planet_t *pla);
void bulletDeath(bullet_t *b);
void bulletCollisions(bullet_t *b,asteroid_t *a,player_t *p);
void bulletOB(bullet_t *b);

//Level
void updateLevel(player_t *p);

#endif /* ENTITIES_H_ */
