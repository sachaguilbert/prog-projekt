#ifndef _INPUT_H_
#define _INPUT_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_rcc.h"
#include "30010_io.h"
#include "stdio.h"
#include "entities.h"
#include "math_st.h"
#include "math.h"
#include "graphics.h"
#include "stdlib.h"
#include "ansi.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define accfactor 0.4
#define velfactor 0.1
#define MAXHP 3

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
uint8_t get_keyboard_input();
void update_player_input();
void update_player_pos(player_t *p);
void LEDSetup();
void LEDHP(player_t* p);



#endif /* _30010_IO_H_ */
