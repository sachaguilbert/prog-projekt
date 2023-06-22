#include "gravity.h"

void updateBulletAcc(bullet_t *b, planet_t *p,uint8_t arrsize){
	//Original formula: xpp += -G*b1.m*(b0.x-b1.x)/Math.pow(d1, 3);
	gotoxy(180,1);
	printf("Xacc: %d",b[0].accx>>14);
	gotoxy(180,2);
	printf("Yacc: %d",b[0].accy>>14);
	uint16_t G = 1;
	int32_t d;
	for(int i=0;i<100;i++){
		if(b[i].damagevalue >0){
			b[i].accx = 0;
			b[i].accy = 0;
			for(int j=0;j<NB_PLANETS;j++){
				int32_t xdist = (b[i].posx - p[j].posx)>>5; //Bit-shifted with five for no overflow
				int32_t ydist = (b[i].posy - p[j].posy)>>5; //Bit-shifted with five for no overflow
				uint8_t hitbox = 10;
				if(xdist < ((hitbox*3)<<9) && xdist > -((hitbox*3)<<9) && ydist < (hitbox<<9) && ydist > -(hitbox<<9)){
					d = sqrt(xdist*xdist + ydist*ydist);
					b[i].accx += (-G*(b[i].posx-p[j].posx)*(1<<5)/(d));
					b[i].accy += (-G*(b[i].posy-p[j].posy)*(1<<5)/(d));
				}
			}
		}
	}
}
