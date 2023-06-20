#ifndef LCD_H_
#define LCD_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "entities.h"
#include "charset.h"
#include "flashmem.h"
#include "string.h"

/* Exported functions ------------------------------------------------------- */
void lcd_scoreboard(player_t p);

#endif /* LCD_H_ */
