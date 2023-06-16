/*
 * menu.h
 *
 *  Created on: Jun 13, 2023
 *      Author: sacha
 */

#ifndef MENU_H_
#define MENU_H_
#include "stdio.h"
#include "stdint.h"
#include "joystick.h"
#include "stm32f30x_conf.h" // STM32 config
void mainMenu();
void helpMenu();
void settingsMenu();
void drawBoxes(uint8_t option, uint8_t action);
void drawStart();
void page();
extern volatile uint32_t score;

#endif /* MENU_H_ */
