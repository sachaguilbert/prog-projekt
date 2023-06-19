#ifndef ADC_H_
#define ADC_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "entities.h"

/* Exported constants --------------------------------------------------------*/
#define JoystickHigh 2000
#define JoystickLow 500

/* Exported functions ------------------------------------------------------- */
uint16_t ADCRead(uint8_t sel);
void movement(player_t *p,bullet_t *b);
void ADCSetup();
#endif /* ADC_H_ */
