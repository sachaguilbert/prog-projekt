/*
 * flashmem.h
 *
 *  Created on: Jun 19, 2023
 *      Author: sacha
 */

#ifndef FLASHMEM_H_
#define FLASHMEM_H_
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "ansi.h"
uint16_t memRead(uint16_t offset);
void memWrite(uint16_t *in,uint8_t sizeofarr);
void clearFlashMem();

#endif /* FLASHMEM_H_ */
