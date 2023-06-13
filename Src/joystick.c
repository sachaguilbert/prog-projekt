#include "joystick.h"

void initPinPC0(){
	GPIOC->MODER &= ~(0x00000003 << (0 * 2));
	GPIOC->MODER |= (0x00000000 << (0 * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (0 * 2));
	GPIOC->PUPDR |= (0x00000002 << (0 * 2));
}
void initPinPA4(){
	GPIOA->MODER &= ~(0x00000003 << (4 * 2));
	GPIOA->MODER |= (0x00000000 << (4 * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (4 * 2));
	GPIOA->PUPDR |= (0x00000002 << (4 * 2));
}
void initPinPB5(){
	GPIOB->MODER &= ~(0x00000003 << (5 * 2));
	GPIOB->MODER |= (0x00000000 << (5 * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (5 * 2));
	GPIOB->PUPDR |= (0x00000002 << (5 * 2));
}
void initPinPC1(){
	GPIOC->MODER &= ~(0x00000003 << (1 * 2));
	GPIOC->MODER |= (0x00000000 << (1 * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2));
	GPIOC->PUPDR |= (0x00000002 << (1 * 2));
}
void initPinPB0(){
	GPIOB->MODER &= ~(0x00000003 << (0 * 2));
	GPIOB->MODER |= (0x00000000 << (0 * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (0 * 2));
	GPIOB->PUPDR |= (0x00000002 << (0 * 2));
}
void initPins(){
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

	initPinPC0();
	initPinPA4();
	initPinPB5();
	initPinPC1();
	initPinPB0();
}
void readJoystick(){
	uint16_t RIGHT = GPIOC->IDR & (0x0001 << 0); //right
	uint16_t UP = GPIOA->IDR & (0x0001 << 4); //up
	uint16_t CENTER = GPIOB->IDR & (0x0001 << 5); //center
	uint16_t LEFT = GPIOC->IDR & (0x0001 << 1); //left
	uint16_t DOWN = GPIOB->IDR & (0x0001 << 0); //down
	gotoxy(0,0);
	if(RIGHT){printf("RIGHT = %u\n", RIGHT);}
	if(UP){printf("UP = %u\n", UP);}
	if(CENTER){printf("CENTER = %u\n", CENTER);}
	if(LEFT){printf("LEFT = %u\n", LEFT);}
	if(DOWN){printf("DOWN = %u\n", DOWN);}
}
int returnCenter(){
	uint16_t CENTER = GPIOB->IDR & (0x0001 << 5); //center
	if(CENTER !=0){return 1;}
}
int returnLeft(){
	uint16_t LEFT = GPIOC->IDR & (0x0001 << 1); //left
	if(LEFT !=0){return 1;}
}
int returnRight(){
	uint16_t RIGHT = GPIOC->IDR & (0x0001 << 0); //right
	if(RIGHT !=0){return 1;}
}
int returnDown(){
	uint16_t DOWN = GPIOB->IDR & (0x0001 << 0); //down
	if(DOWN !=0){return 1;}
}
int returnUp(){
	uint16_t UP = GPIOA->IDR & (0x0001 << 4); //up
	if(UP !=0){return 1;}
}
