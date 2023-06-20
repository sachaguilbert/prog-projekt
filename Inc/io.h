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
#include "charset.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define accfactor 0.4
#define velfactor 0.1
#define MAXHP 3

/* Exported macro ------------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

// ON BOARD JOYSTICK
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

// KEYBOARD
uint8_t get_keyboard_input();

// LED
void LEDSetup();
void LEDHP(player_t* p);
void setLED(uint8_t r,uint8_t g,uint8_t b);

// ADC / Joystick
uint16_t ADCRead(uint8_t sel);
void ADCSetup();

// LCD
void lcd_write_string(char str[],uint32_t loc);

// MEMORY
uint16_t memRead(uint16_t offset);
void memWrite(uint16_t *in,uint8_t sizeofarr);
void clearFlashMem();

#endif /* _30010_IO_H_ */
