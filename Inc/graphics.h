/*
 * graphics.h
 *
 *  Created on: 9. jun. 2023
 *      Author: alber
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "math_st.h"
#include "globalTimer.h"


//FUNCTIONS
void drawGameStart();

void drawPlayer(player_t p,uint8_t init,vector_t *v);
void drawPlanet(planet_t p);
void deletePlayer(player_t p);
void bitShift(vector_t *v);
vector_t redPixelPos(player_t p);
void drawRedPixel(player_t p);



void drawBullets(bullet_t *p);
void drawAstroids(astroid_t *a);


void createAnnouncement(char *str);
void clearAnnouncement();


#endif /* GRAPHICS_H_ */
