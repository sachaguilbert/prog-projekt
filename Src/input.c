#include "input.h"

uint8_t get_keyboard_input()
{
	return uart_get_char();
}

void update_player_input(player_t *p)
{
	uint8_t input = get_keyboard_input();
	switch(input)
	{
	case 97: //a left
		p->dir+=10;
		p->accx = cosLUT(p->dir);
		p->accy = sinLUT(p->dir);
		break;
	case 100: //d right
		p->dir-=10;
		p->accx = cosLUT(p->dir);
		p->accy = sinLUT(p->dir);
		break;
	case 119: //w forward
		p->velx+= p->accx;
		p->vely+= p->accy;
		break;
	case 115: //s back
		p->velx-= p->accx;
		p->vely-= p->accy;
		break;
	case 32: //SPACE shoot
//		create_bullet();
		break;
	}
}
void update_player_pos(player_t *p)
{
	p->posx += p->velx;
	p->posy += p->vely;
}
