#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include "entities.h"
#include "graphics.h"
#include "input.h"
#include "math_st.h"

int main(void)
{
	bullet_t bullets[100];
	astroid_t astriods[100];


	uart_init(115200);
	clrscr();
	//drawGameStart();
	player_t p;
	p.posx = 10 << 14;
	p.posy = 10 << 14;
	p.dir = 0;
	p.velx = 0;
	p.vely = 0;
	p.accx = 1 << 14;
	p.accy = 0;

	while(1){
		if(uart_get_count() > 0)
		{
			update_player_input(&p);
			gotoxy(0,14);
			printf("input");

		} else{
			gotoxy(0,14);
			printf("false");
		}
		drawBullets(bullet_t p[]);
		update_player_pos(&p);
		stm_sleep(10);
		gotoxy(0,0);
		printf("%d\n",p.posx >> 14);
		printf("%d\n",p.posy >> 14);
		printf("\n%d\n",p.velx >> 14);
		printf("%d\n",p.vely >> 14);
		printf("\n%d\n",p.accx >> 14);
		printf("%d\n",p.accy >> 14);
		printf("\n%d\n",p.dir);
		drawPlayer(p);




	}
}
