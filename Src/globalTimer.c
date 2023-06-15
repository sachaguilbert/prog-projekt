#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"

volatile uint8_t globalTick;


void tim15Setup(){
	RCC->APB2ENR |= RCC_APB2Periph_TIM15; // Enable clock line to timer 15;
	TIM15->CR1 = 0x0000000000000000; // Configure timer 15
	TIM15->ARR = 0x27F; // Set reload value
	TIM15->PSC = 0x3E8; // Set prescale value

	TIM15->DIER |= 0x0001; // Enable timer 15 interrupts
	NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 2); // Set interrupt priority
	NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);
	TIM15->CR1 = 0x0000000000000001; // Configure timer 15
}

void TIM1_BRK_TIM15_IRQHandler(void) {
	globalTick++;
	//Do whatever you want here, but make sure it doesn’t take too much Time.
	TIM15->SR &= ~0x0001; // Clear interrupt bit
}
