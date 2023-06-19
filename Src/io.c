#include "io.h"

uint8_t get_keyboard_input()
{
	return uart_get_char();
}

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

void LEDHP(player_t* p){

	if(p->hitpoints >= MAXHP){
		setLED(0,1,0);
	}else if(p->hitpoints < MAXHP && p->hitpoints > 1){
		setLED(1,1,0);
	}else if(p->hitpoints == 1){
		setLED(1,0,0);
	}
}

void update_player_input()
{
	// Limits inputs to 3 per tick
	uint8_t i = 0;
	while(uart_get_count()>0 && i<3){
		uint8_t input = get_keyboard_input();
		if(input == 98){
			NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);
			clrscr();
			gotoxy(1,1);
			char hallal[5] = "Haram";
		    int rows = 40;    // Number of rows in the Excel sheet
		    int columns = 15; // Number of columns in the Excel sheet

		    // ASCII art for the Excel sheet
		    printf(" ");
		    for(int i = 1; i<columns;i++){
		    printf("_________");
		    }
		    printf("\n|");
		    for(int i = 1; i<columns;i++){
		    printf("         ");
		    }
		    printf("|\n");
		    // Print column headers (A, B, C, ...)
		    printf("|      ");
		    for (int i = 0; i < columns; i++) {
		        printf("|   %c   ", 'A' + i);
		    }
		    printf("|\n");

		    // Print horizontal separator
		    printf("|______");
		    for (int i = 0; i < columns; i++) {
		        printf("|_______");
		    }
		    printf("|\n");

		    // Print rows with cell values
		    for (int row = 1; row <= rows; row++) {
		        printf("|   %2d ", row);

		        for (int col = 0; col < columns; col++) {
		            printf("|   %3u ", rand() %999);
		        }
		        printf("|\n");
		    }

		    // Print bottom border
		    printf("|______");
		    for (int i = 0; i < columns; i++) {
		        printf("|_______");
		    }
		    printf("|\n");
			while(1){

				if(uart_get_count()>0){

					if(get_keyboard_input() == 98){
						clrscr();
						break;
					}
				}
			}
			NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

		}
		i++;
	}
	uart_clear();
}
void update_player_pos(player_t *p)
{

	p->posx += p->velx;
	p->posy += p->vely;
	if((p->velx >> 12) > 0)
	{
		p->velx-= (1 << 11);
	} else if((p->velx >> 12) < 0)
	{
		p->velx+= (1 << 11);
	}
	if((p->vely >> 12) > 0)
	{
			p->vely-= (1 << 11);
	} else if((p->vely >> 12) < 0)
	{
		p->vely+= (1 << 11);
	}
	p->velx = abs(p->velx) < (1 << 12) ? 0 : p->velx;
	p->vely = abs(p->vely) < (1 << 12) ? 0 : p->vely;

	p->posx = p->posx >= (WIN_WIDTH - 5) << 14 ? 5 << 14 : p->posx;
	p->posy = p->posy >= (WIN_HEIGHT - 4) << 14 ? 5 << 14 : p->posy;
	p->posx = p->posx <= 4 << 14 ? (WIN_WIDTH - 6) << 14: p->posx;
	p->posy = p->posy <= 4 << 14 ? (WIN_HEIGHT - 5) << 14 : p->posy;

}
