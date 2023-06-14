#include "gravity.h"
#include "math.h"

void updateBulletAcc(bullet_t *b, planet_t p){
	//Original formula: xpp += -G*b1.m*(b0.x-b1.x)/Math.pow(d1, 3);
	uint8_t mass = 1;
	uint16_t G = 3;
	for(int i=0;i<100;i++){
		//if statement to filter all dead bullets
		if(b[i].damagevalue !=0){
			//if statement to filter all bullets too far away
			if((b[i].posx-p.posx)>>14 < 20 && (b[i].posx-p.posx)>>14 > -20 && (b[i].posy-p.posy)>>14 < 20 && (b[i].posy-p.posy)>>14 > -20){
				int32_t d = sqrt(((b[i].posx-p.posx)>>10)*((b[i].posx-p.posx)>>10)+ ((b[i].posy-p.posy)>>10)*((b[i].posy-p.posy)>>10));
				int32_t calc = ((1<<14)/(d>>4)) * ((1<<14)/(d>>4));
				int32_t shiftCalc = calc>>14;
				int32_t finalCalc = shiftCalc * ((1<<14)/(d>>4));
				int32_t ddx = -G*mass*((b[i].posx-p.posx)>>14)* finalCalc;
				int32_t ddy = -G*mass*((b[i].posy-p.posy)>>14)* finalCalc;
				//if statement to avoid dividing by d=0
				if((d>>4) > 10){
					b[i].accx = ddx>>14;
					b[i].accy = ddy>>14;
				}
			}
		}
	}
}
