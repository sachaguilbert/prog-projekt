#ifndef GLOBALTIMER_H_
#define GLOBALTIMER_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"

/* Exported constants --------------------------------------------------------*/
extern volatile uint16_t announcTick;
extern volatile uint8_t globalTick;

/* Exported functions ------------------------------------------------------- */
void TIM1_BRK_TIM15_IRQHandler(void);
void tim15Setup();


#endif /* GLOBALTIMER_H_ */
