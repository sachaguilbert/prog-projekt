/*
 * ADC.c
 *
 *  Created on: 8. jun. 2023
 *      Author: alber
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "entities.h"

#define JoystickHigh 2000
#define JoystickLow 500


uint16_t ADCRead(uint8_t sel){
	uint16_t x;
	switch(sel){
	case 0:
		ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_1Cycles5);
		ADC_StartConversion(ADC1); // Start ADC read
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

		x = ADC_GetConversionValue(ADC1); // Read the ADC value
		break;

	case 1:
		ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_1Cycles5);
		ADC_StartConversion(ADC1); // Start ADC read
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

		x = ADC_GetConversionValue(ADC1); // Read the ADC value
		break;
	case 2:
		ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_1Cycles5);
		ADC_StartConversion(ADC1); // Start ADC read
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

		x = ADC_GetConversionValue(ADC1); // Read the ADC value
		break;
	case 3:
		ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 1, ADC_SampleTime_1Cycles5);
		ADC_StartConversion(ADC1); // Start ADC read
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == 0); // Wait for ADC read

		x = ADC_GetConversionValue(ADC1); // Read the ADC value
		break;

	}
	return x;


}

void ADCSetup(){

	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port A
	// Set pin PC0 to input
	GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000000 << (0 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	// Set pin PC1 to input
	GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (1 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000000 << (1 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	// C1
	GPIOC->MODER &= ~(0x00000003 << (2 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (2 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (2 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000000 << (2 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)
	// Set pin PC1 to input
	GPIOC->MODER &= ~(0x00000003 << (3 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (3 * 2)); // Set mode register (0x00 –Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (3 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000000 << (3 * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)




	RCC->CFGR2 &= ~RCC_CFGR2_ADCPRE12; // Clear ADC12 prescaler bits
	RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV6; // Set ADC12 prescaler to 6
	RCC->AHBENR |= RCC_AHBPeriph_ADC12; // Enable clock for ADC12

	ADC1->CR = 0x00000000; // Clear CR register
	ADC1->CFGR &= 0xFDFFC007; // Clear ADC1 config register
	ADC1->SQR1 &= ~ADC_SQR1_L; // Clear regular sequence register 1

	ADC1->CR |= 0x10000000; // Enable internal ADC voltage regulator
	for (int i = 0 ; i < 1000 ; i++) {} // Wait for about 16 microseconds

	ADC1->CR |= 0x80000000; // Start ADC1 calibration
	while (!(ADC1->CR & 0x80000000)); // Wait for calibration to finish
	for (int i = 0 ; i < 100 ; i++) {} // Wait for a little while

	ADC1->CR |= 0x00000001; // Enable ADC1 (0x01 - Enable, 0x02 - Disable)
	while (!(ADC1->ISR & 0x00000001)); // Wait until ready




}

void movement(player_t *p,bullet_t *b){
	uint16_t j1 = ADCRead(1);
	if(j1 >= JoystickHigh){
		p->velx += p->accx;
		p->dir = 0;
	}
	if(j1 <= JoystickLow){
		p->velx -= p->accx;
		p->dir = 4;
	}
	uint16_t j2 = ADCRead(0);
	if(j2 >= JoystickHigh){
		p->vely -= p->accx >> 1;
		p->dir = 2;
	}
	if(j2 <= JoystickLow){
		p->vely += p->accx >> 1;
		p->dir = 6;
	}

	if(j1 >= JoystickHigh && j2 >= JoystickHigh){p->dir = 1;}
	if(j1 >= JoystickHigh && j2 <= JoystickHigh){p->dir = 7;}
	if(j1 <= JoystickHigh && j2 >= JoystickHigh){p->dir = 3;}
	if(j1 <= JoystickHigh && j2 <= JoystickHigh){p->dir = 5;}





	uint16_t b1 = ADCRead(3);
	if(b1 >= 4000){
		createBullet(*p,b);
	}


	// Limit
	p->velx = p->velx >= 2 << 14 ? 2 << 14 : p->velx;
	p->vely = p->vely >= 2 << 14 ? 2 << 14 : p->vely;
	p->velx = p->velx <= -2 << 14 ? -2 << 14 : p->velx;
	p->vely = p->vely <= -2 << 14 ? -2 << 14 : p->vely;

}

