#include "gravity.h"
#include "math.h"

/*void initSpaceShip(ship_t *ship, int16_t x, int16_t y, int16_t dx, int16_t dy){
	ship->x = x<<5;
	ship->y = y<<5;
	ship->dx = dx<<5;
	ship->dy = dy<<5;
}
void initAsteroid(asteroid_t *ast, int16_t x, int16_t y, int16_t dx, int16_t dy, int16_t mass){
	ast->x = x<<5;
	ast->y = y<<5;
	ast->dx = 0;
	ast->dy = 0;
}*/
void updateShipPos(player_t *play, astroid_t *ast){
	//int16_t d = sqrt((ship->x-ast->x)*(ship->x-ast->x) + (ship->y-ast->y)*(ship->y-ast->y));
	//int16_t dsqr = d * d>>5;
	//int16_t dcub = dsqr>>5 * d>>5;
	//int16_t G = 1;
	//int16_t ddx = -G*ast->mass*(ast->x-ship->x)/(dsqr*dsqr*dsqr);
	//int16_t ddy = -G*ast->mass*(ast->y-ship->y)/(dsqr*dsqr*dsqr);
	uint8_t mass = 1;
	float d = sqrt((play->posx-((ast->posx)>>5))*(play->posx-((ast->posx)>>5)) + (play->posy-((ast->posy)>>5))*(play->posy-((ast->posy)>>5)));
	float G = 0.00000005;
	float ddx = -G*mass*(play->posx-(ast->posx>>5))/(d*d*d);
	float ddy = -G*mass*(play->posy-(ast->posy>>5))/(d*d*d);
	gotoxy(1,10);
	printf("ddx: %05d",(int)(ddx*10));
	gotoxy(1,11);
	printf("ddy: %05d",(int)(ddy*10));
	gotoxy(1,12);
	printf("d: %05d",(int)(d));
	gotoxy(1,13);
	printf("%05d",(int)(play->posx-((ast->posx)>>5)));
	play->velx += ddx;
	play->vely += ddy;
	play->posx += play->velx;
	play->posy += play->vely;
}
