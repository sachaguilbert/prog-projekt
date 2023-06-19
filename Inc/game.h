#ifndef GAME_H_
#define GAME_H_

/* Includes ------------------------------------------------------------------*/
#include "30010_io.h"
#include "ansi.h"
#include "ADC.h"
#include "menu.h"
#include "io.h"
/* Exported constants --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void gameInit();
void updatePlayer(player_t *p);
#endif /* ADC_H_ */
