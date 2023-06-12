#ifndef _INPUT_H_
#define _INPUT_H_

/* Includes ------------------------------------------------------------------*/
#include "30010_io.h"
#include <stdio.h>
#include "entities.h"
#include "math_st.h"
#include <math.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
uint8_t get_keyboard_input();
void update_player_input(player_t *p,bullet_t *b);
void update_player_pos(player_t *p);




#endif /* _30010_IO_H_ */
