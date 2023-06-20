#include "gravity.h"

void updateBulletAcc(bullet_t *b, planet_t *p,uint8_t arrsize){
	//Original formula: xpp += -G*b1.m*(b0.x-b1.x)/Math.pow(d1, 3);
	uint8_t mass = 1;
	uint16_t G = 1;
	int32_t d;
	for(int i=0;i<10;i++){
		if(b[i].damagevalue >0){
			for(int j=0;j<arrsize;j++){
				int32_t xdist = (b[i].posx - p[0].posx)>>5; //Bit-shifted with five for no overflow
				int32_t ydist = (b[i].posy - p[0].posy)>>5;
				d = sqrt(xdist*xdist + ydist*ydist);
				b[i].accx = -G*(b[i].posx-p[0].posx)*(1<<5)/d;
				b[i].accy = -G*(b[i].posy-p[0].posy)*(1<<5)/d;
			}
			gotoxy(180,1+i);
			printf("X accel: %05d",b[i].accx);
			gotoxy(180,2+i*2);
			printf("Distance: %05d",d);
		}
	}
	/*for(int i=0;i<100;i++){
		b[i].accx = 0;
		b[i].accy = 0;
		for(int j=0;j<arrsize;j++){
			//if statement to filter all dead bullets
			if(b[i].damagevalue >0){
				//if statement to filter all bullets too far away
				if((b[i].posx-p[j].posx)>>14 < 10 && (b[i].posx-p[j].posx)>>14 > -10 && (b[i].posy-p[j].posy)>>14 < 10 && (b[i].posy-p[j].posy)>>14 > -10){
					int64_t d = sqrt(((b[i].posx-p[j].posx)>>10)*((b[i].posx-p[j].posx)>>10)+ ((b[i].posy-p[j].posy)>>10)*((b[i].posy-p[j].posy)>>10));
					int64_t calc = ((1<<14)/(d>>4)) * ((1<<14)/(d>>4));
					int64_t shiftCalc = calc>>14;
					int64_t finalCalc = shiftCalc * ((1<<14)/(d>>4));
					int64_t ddx = -G*mass*((b[i].posx-p[j].posx)>>14)* finalCalc;
					int64_t ddy = -G*mass*((b[i].posy-p[j].posy)>>14)* finalCalc;
					//if statement to avoid dividing by d=0
					if((d>>4) > 5){
						b[i].accx += ddx>>20;
						b[i].accy += ddy>>20;
					}
				}
			}
		}
		gotoxy(160,1+i*2);
		printf("X-accel: %010d",b[i].accx);
		gotoxy(160,2+i*2);
		printf("Y-accel: %010d",b[i].accy);
	}*/
}
