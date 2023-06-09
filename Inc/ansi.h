/*
 * ansi.h
 *
 *  Created on: 1. jun. 2023
 *      Author: alber
 */

#ifndef _ANSI_H_
#define _ANSI_H_
/* Includes -------------------------------------------------------------*/
#include "stdint.h"
#include "stdio.h"
/* Exported types -------------------------------------------------------*/
/* Exported constants ---------------------------------------------------*/
/* Exported macro -------------------------------------------------------*/
/* Exported functions -------------------------------------------------- */
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void window(uint8_t p1[2],uint8_t p2[2],char title[], uint8_t style);
void gameWindow(uint8_t p1[2],uint8_t p2[2], uint8_t style);
void gotoxy(uint8_t x,uint8_t y);
void blink(uint8_t on);
void reverse(uint8_t on);
void clrscr();
void clreol();
void underline(uint8_t on);
#endif /* _ANSI_H_ */
