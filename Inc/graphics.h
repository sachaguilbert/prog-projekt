#ifndef GRAPHICS_H_
#define GRAPHICS_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "entities.h"
#include "math_st.h"
#include "math.h"
#include "stdio.h"
#include "stdint.h"
#include "globalTimer.h"
#include "stdlib.h"
#include "ansi.h"
#include "math.h"
#include "graphics.h"
#include "window.h"

/* Exported constants --------------------------------------------------------*/
#define velfactor 0.1

/* Exported functions ------------------------------------------------------- */
//FUNCTIONS
void drawGameStart();

void drawPlayer(player_t p,uint8_t init,vector_t *v);
void drawPlanets(planet_t *p,uint8_t arrsize);
void deletePlayer(player_t p);
void bitShift(vector_t *v);
vector_t redPixelPos(player_t p);
void drawRedPixel(player_t p);

void drawBullets(bullet_t *p);
void drawAstroids(astroid_t *a);

void createAnnouncement(char *str);
void clearAnnouncement();


#endif /* GRAPHICS_H_ */
