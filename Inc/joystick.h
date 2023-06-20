#ifndef JOYSTICK_H_
#define JOYSTICK_H_
/* Includes ------------------------------------------------------------------*/
#include "stm32f30x_conf.h" // STM32 config
#include "ansi.h"
#include "stdio.h"
#include "stdint.h"

/* Exported functions ------------------------------------------------------- */
void initPinPC0();
void initPinPA4();
void initPinPB5();
void initPinPC1();
void initPinPB0();
void initPins();
void readJoystick();
int returnCenter();
int returnLeft();
int returnRight();
int returnDown();
int returnUp();

#endif /* JOYSTICK_H_ */
