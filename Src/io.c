#include "io.h"

uint8_t get_keyboard_input()
{
	return uart_get_char();
}

// ON BOARD JOYSTICK


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


// LED
void LEDSetup(){

	uint8_t blue = 9;
	uint8_t red = 4;
	uint8_t green = 7;



	// Set pin PA1 to output
	GPIOA->OSPEEDR &= ~(0x00000003 << (blue * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (blue * 2)); // set speed register (0x01 - 10
	GPIOA->OTYPER &= ~(0x0001 << (blue * 2)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (blue * 2)); // Set output type register (0x00 -
	GPIOA->MODER &= ~(0x00000003 << (blue * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (blue * 2)); // Set mode register (0x00 –input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (blue * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (blue * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)



	GPIOB->OSPEEDR &= ~(0x00000003 << (red * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (red * 2)); // set speed register (0x01 - 10
	GPIOB->OTYPER &= ~(0x0001 << (red * 2)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (red * 2)); // Set output type register (0x00 -
	GPIOB->MODER &= ~(0x00000003 << (red * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000001 << (red * 2)); // Set mode register (0x00 –input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOB->PUPDR &= ~(0x00000003 << (red * 2)); // Clear push/pull register
	GPIOB->PUPDR |= (0x00000002 << (red * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)


	GPIOC->OSPEEDR &= ~(0x00000003 << (green * 2)); // Clear speed register
	GPIOC->OSPEEDR |= (0x00000002 << (green * 2)); // set speed register (0x01 - 10
	GPIOC->OTYPER &= ~(0x0001 << (green * 2)); // Clear output type register
	GPIOC->OTYPER |= (0x0000 << (green * 2)); // Set output type register (0x00 -
	GPIOC->MODER &= ~(0x00000003 << (green * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000001 << (green * 2)); // Set mode register (0x00 –input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (green * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (green * 2)); // Set push/pull register (0x00 -No pull, 0x01 - Pull-up, 0x02 - Pull-down)




}

void setLED(uint8_t r,uint8_t g,uint8_t b){
	uint8_t blue = 9;
	uint8_t red = 4;
	uint8_t green = 7;
	if(r){
		GPIOB->ODR &= ~(0x0001 << red);
	}else{
		GPIOB->ODR |= (0x0001 << red);
	}
	if(g){
		GPIOC->ODR &= ~(0x0001 << green);
	}else{
		GPIOC->ODR |= (0x0001 << green);
	}
	if(b){
		GPIOA->ODR &= ~(0x0001 << blue);
	}else{
		GPIOA->ODR |= (0x0001 << blue);
	}
/*r ? GPIOB->ODR &= (0x0000 << red) : GPIOB->ODR |= (0x0001 << red) ; //Set pin PA1 to high
	g ? GPIOC->ODR &= (0x0000 << green) : GPIOC->ODR |= (0x0001 << green) ; //Set pin PA1 to high
	b ? GPIOA->ODR &= (0x0000 << blue) : GPIOA->ODR |= (0x0001 << blue) ; //Set pin PA1 to high
*/
}

// ADC / JOYSTICK
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

// LCD

void lcd_write_string(char str[],uint32_t loc){
	uint8_t buffer[512];
	uint16_t i,j;
	memset(buffer,0x00,512);

	for(i=0;i<strlen(str);i++){
		uint8_t ch = str[i]-0x20;
		for(j=0;j<5;j++){
			buffer[loc+j] = character_data[ch][j];
		}
		loc +=5;
	}

	lcd_push_buffer(buffer);
}

// Memory

uint16_t memRead(uint16_t offset){
	uint32_t baseAddress = 0x0800F800;
	uint16_t returnVal;
	returnVal = *(uint16_t *)(baseAddress + offset*2); // Read Command
	return returnVal;
}

void memWrite(uint16_t *in,uint8_t sizeofarr){
	uint32_t baseAddress = 0x0800F800;
	FLASH_Unlock();
	FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR );
	FLASH_ErasePage( baseAddress );
	for(uint16_t i = 0; i<sizeofarr;i++){
		FLASH_ProgramHalfWord(baseAddress+i*2, in[i]);
	}
	FLASH_Lock();
}

void clearFlashMem(){
	uint32_t baseAddress = 0x0800F800;
	FLASH_Unlock();
	FLASH_ClearFlag( FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPERR );
	FLASH_ErasePage( baseAddress );
	FLASH_ProgramHalfWord(baseAddress, 0);
	FLASH_Lock();
}
