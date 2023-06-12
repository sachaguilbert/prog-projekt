#include "input.h"
#include "entities.h"
#define accfactor 0.1
#define velfactor 0.1

uint8_t get_keyboard_input()
{
	return uart_get_char();
}

void update_player_input(player_t *p,bullet_t *b)
{
	// Limits inputs to 3 per tick
	uint8_t i = 0;
	while(uart_get_count()>0 && i<3){
	uint8_t input = get_keyboard_input();
	switch(input)
	{
	case 100: //d left
		p->dir+=15;
		p->dir = p->dir >= 512 ? 0 : p->dir;

		p->accx = cosLUT(p->dir);
		p->accy = sinLUT(p->dir);
		break;
	case 97: //a right
		p->dir-=15;
		p->dir = p->dir <= 0 ? 512 : p->dir;

		p->accx = cosLUT(p->dir);
		p->accy = sinLUT(p->dir);
		break;
	case 119: //w forward
		p->velx+= p->accx * accfactor;
		p->vely+= p->accy * accfactor;
		p->velx = p->velx >= 2 << 14 ? 2 << 14 : p->velx;
		p->vely = p->vely >= 2 << 14 ? 2 << 14 : p->vely;
		p->velx = p->velx <= -2 << 14 ? -2 << 14 : p->velx;
		p->vely = p->vely <= -2 << 14 ? -2 << 14 : p->vely;
		break;
	case 115: //s back
		p->velx-= p->accx * accfactor;
		p->vely-= p->accy * accfactor;
		p->velx = p->velx >= 2 << 14 ? 2 << 14 : p->velx;
		p->vely = p->vely >= 2 << 14 ? 2 << 14 : p->vely;
		p->velx = p->velx <= -2 << 14 ? -2 << 14 : p->velx;
		p->vely = p->vely <= -2 << 14 ? -2 << 14 : p->vely;
		break;
	case 32: //SPACE shoot
		createBullet(*p,b);
		break;
	}
	i++;
	}
	uart_clear();
}
void update_player_pos(player_t *p)
{
	p->posx += p->velx * velfactor;
	p->posy += p->vely * velfactor;
}
