/*
 * player.h
 *
 *  Created on: 20. jun. 2023
 *      Author: alber
 */

#ifndef PLAYER_H_
#define PLAYER_H_

// INCLUDES
#include "math_st.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "ansi.h"
#include "math.h"
#include "window.h"
#include "io.h"

// CONST
#define JoystickHigh 2000
#define JoystickLow 500



// FUNCTIONS
void LEDHP(player_t* p);
void initPlayer(player_t *p);
void movement(player_t *p,bullet_t *b);
void update_player_input();
void update_player_pos(player_t *p);

#endif /* PLAYER_H_ */
