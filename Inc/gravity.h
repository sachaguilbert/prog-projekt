#ifndef GRAVITY_H_
#define GRAVITY_H_
#include "stdio.h"
#include "stdint.h"
#include "entities.h"

//void initSpaceShip(ship_t *ball, int16_t x, int16_t y, int16_t dx, int16_t dy);
//void initAsteroid(asteroid_t *ast, int16_t x, int16_t y, int16_t dx, int16_t dy, int16_t mass);
void updateShipPos(player_t *play, astroid_t *ast);
#endif /* GRAVITY_H_ */
