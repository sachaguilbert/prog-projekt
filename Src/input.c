#include "input.h"
#define accfactor 0.1
#define velfactor 0.1

uint8_t get_keyboard_input()
{
	return uart_get_char();
}

void update_player_input(player_t *p,bullet_t *b[])
{
	uint8_t input = get_keyboard_input();
	switch(input)
	{
	case 97: //a left
		p->dir+=1;
		p->accx = cosLUT(p->dir);
		p->accy = sinLUT(p->dir);
		break;
	case 100: //d right
		p->dir-=1;
		p->accx = cosLUT(p->dir);
		p->accy = sinLUT(p->dir);
		break;
	case 119: //w forward
		p->velx+= p->accx * accfactor;
		p->vely+= p->accy * accfactor;
		break;
	case 115: //s back
		p->velx-= p->accx * accfactor;
		p->vely-= p->accy * accfactor;
		break;
	case 32: //SPACE shoot
		create_bullet(&p,&b);
		break;
	}
}
void update_player_pos(player_t *p)
{
	p->posx += p->velx * velfactor;
	p->posy += p->vely * velfactor;
}
