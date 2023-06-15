#include "input.h"
#include "entities.h"
#define accfactor 0.4
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
		p->velx+= p->accx;
		p->vely+= p->accy;
		p->velx = p->velx >= 2 << 14 ? 2 << 14 : p->velx;
		p->vely = p->vely >= 2 << 14 ? 2 << 14 : p->vely;
		p->velx = p->velx <= -2 << 14 ? -2 << 14 : p->velx;
		p->vely = p->vely <= -2 << 14 ? -2 << 14 : p->vely;
		break;
	case 115: //s back
		p->velx-= p->accx;
		p->vely-= p->accy;
		p->velx = p->velx >= 1 << 14 ? 1 << 14 : p->velx;
		p->vely = p->vely >= 1 << 14 ? 1 << 14 : p->vely;
		p->velx = p->velx <= -1 << 14 ? -1 << 14 : p->velx;
		p->vely = p->vely <= -1 << 14 ? -1 << 14 : p->vely;
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

	p->posx = p->posx >= 150 << 14 ? 7 << 14 : p->posx;
	p->posy = p->posy >= 84 << 14 ? 7 << 14 : p->posy;
	p->posx = p->posx <= 6 << 14 ? 149 << 14: p->posx;
	p->posy = p->posy <= 6 << 14 ? 83 << 14 : p->posy;

}
