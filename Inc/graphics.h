/*
 * graphics.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_


//FUNCTIONS
void drawGameStart();

void drawPlayer(player_t p);
void drawPlayerPixel(player_t p, int8_t x, int8_t y,uint8_t ch);
void drawPlanet(planet_t p);
void deletePlayer(player_t p);

void drawBullets(bullet_t *p);
void drawAstroids(astroid_t *a);

#endif /* GRAPHICS_H_ */
