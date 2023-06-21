#ifndef MENU_H_
#define MENU_H_
#include "stdio.h"
#include "stdint.h"
#include "io.h"
#include "entities.h"
#include "graphics.h"
#include "stm32f30x_conf.h"// STM32 config


void bossKey();
void mainMenu();
void helpMenu();
void settingsMenu();
void drawBoxes(uint8_t option, uint8_t action);
void drawStart();
void page();
int gameOver(player_t* p);
extern volatile uint32_t score;

#endif /* MENU_H_ */
