#include "input.h"

uint8_t get_keyboard_input()
{
	return uart_get_char();
}

void update_player_input(struct player *p)
{
	uint8_t input = get_keyboard_input();
	switch(input)
	{
	case 97: //a left
		p->dir+=1;
		p->ax = cosLUT(p->dir);
		p->ay = sinLUT(p->dir);
		break;
	case 100: //d right
		p->dir-=1;
		p->ax = cosLUT(p->dir);
		p->ay = sinLUT(p->dir);
		break;
	case 119: //w forward
		p->vx+= p->ax;
		p->vy+= p->ay;
		break;
	case 115: //s back
		p->vx-= p->ax;
		p->vy-= p->ay;
		break;
	case 32: //SPACE shoot
//		create_bullet();
		break;
	}
}
