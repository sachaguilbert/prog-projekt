#ifndef _INPUT_H_
#define _INPUT_H_

/* Includes ------------------------------------------------------------------*/
#include "30010_io.h"
#include <stdio.h>
#include "entities.h"
#include "math_st.h"
#include <math.h>
#include "graphics.h"
#include <stdlib.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
uint8_t get_keyboard_input();
void update_player_input();
void update_player_pos(player_t *p);
void LEDSetup();
void LEDHP(player_t* p);



#endif /* _30010_IO_H_ */