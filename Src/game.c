#include "game.h"

void gameInit()
{
	uart_init(921600);
	lcd_init();
	ADCSetup();
	clrscr();
	page();
	LEDSetup();
	tim15Setup();
}

void updatePlayer(player_t *p)
{
	deletePlayer(*p);
	update_player_pos(p);
	drawPlayer(*p);
}
