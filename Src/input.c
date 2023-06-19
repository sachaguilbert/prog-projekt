#include "input.h"
#include "entities.h"
#include "ansi.h"
#define accfactor 0.4
#define velfactor 0.1

uint8_t get_keyboard_input()
{
	return uart_get_char();
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
	p->oldPos.x = redPixelPos(*p).x;
	p->oldPos.y = redPixelPos(*p).y;

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

	p->posx = p->posx >= 152 << 14 ? 5 << 14 : p->posx;
	p->posy = p->posy >= 86 << 14 ? 5 << 14 : p->posy;
	p->posx = p->posx <= 4 << 14 ? 151 << 14: p->posx;
	p->posy = p->posy <= 4 << 14 ? 85 << 14 : p->posy;

}
