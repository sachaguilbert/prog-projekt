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
void updateBulletPos(bullet_t *b, planet_t p){
	//Original formula: xpp += -G*b1.m*(b0.x-b1.x)/Math.pow(d1, 3);
	uint8_t mass = 1;
	uint16_t G = 2;
	int32_t d = sqrt(((b[0].posx-p.posx)>>10)*((b[0].posx-p.posx)>>10)+ ((b[0].posy-p.posy)>>10)*((b[0].posy-p.posy)>>10));//*((b[0].posx-p.posx)>>10);//sqrt((b[0].posx-p.posx)*(b[0].posx-p.posx) + (b[0].posy-p.posy)*(b[0].posy-p.posy));
	int32_t calc = ((1<<14)/(d>>4)) * ((1<<14)/(d>>4));
	int32_t shiftCalc = calc>>14;
	int32_t finalCalc = shiftCalc * ((1<<14)/(d>>4));
	int32_t ddx = -G*mass*((b[0].posx-p.posx)>>14)* finalCalc;
	int32_t ddy = -G*mass*((b[0].posy-p.posy)>>14)* finalCalc;
	/*gotoxy(0,0);
	printf("Bullet x: %d\n",b[0].posx>>14);
	printf("Bullet y: %d\n",b[0].posy>>14);
	printf("Planet x: %d\n",p.posx>>14);
	printf("Planet y: %d\n",p.posy>>14);
	//printf("Distancex: %d\n",(b[0].posx-p.posx)>>14);
	//printf("Distancey: %05d\n",(b[0].posy-p.posy)>>14);
	printf("Distance cubed: %05d\n",(d>>4) * (d>>4)* (d>>4));
	printf("1/d^3: %05d\n",finalCalc>>14);
	printf("ddx test: %05d\n",ddx);*/
	b[0].velx += ddx>>14;
	b[0].vely += ddy>>14;
	b[0].posx += b->velx*0.1;
	b[0].posy += b->vely*0.1;
}
