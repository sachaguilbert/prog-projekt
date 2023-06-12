#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "entities.h"
#include "ansi.h"
#include "math.h"
#define velfactor 0.5


void initPlayer(player_t *pla, int32_t x, int32_t y, int32_t dx, int32_t dy){
	pla->posx = x;
	pla->posy = y;
	pla->velx = dx;
	pla->vely = dy;
}
void initAsteroid(astroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy){
	ast->posx = x;
	ast->posy = y;
	ast->velx = dx;
	ast->vely = dy;
	ast->style = 1;
	if(ast->style == 1){
		ast->hitpoints = 10;
	}else if(ast->style == 2){
		ast->hitpoints = 20;
	}else{
		ast->hitpoints = 30;
	}
}
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style){
	planet->posx = x;
	planet->posy = y;
	planet->style = style;
}

void astroidRandom(astroid_t *a){
	astroid_t ast;
	ast.style =1;
	uint8_t sel = rand() % 4;
	ast.velx = ((rand() % 3)<<14)*0.1;
	ast.vely = ((rand() % 3)<<14)*0.1;
	switch(sel){
	case 0:
		initAsteroid(&ast,(rand() % 150)<<14,2<<14,rand() %2 ? ast.velx : -ast.velx,ast.vely);
		break;
	case 1:
		initAsteroid(&ast,(rand() % 150)<<14,50<<14,rand() %2 ? ast.velx : -ast.velx,-ast.vely);
		break;
	case 2:
		initAsteroid(&ast,2<<14,(rand() % 50)<<14,ast.velx,rand() %2 ? ast.vely : -ast.vely);
		break;
	case 3:
		initAsteroid(&ast,150<<14,(rand() % 50)<<14,-ast.velx,rand() %2 ? ast.vely : -ast.vely);
		break;

	}

	uint16_t j =0;
	while(j<100){
		if(a[j].hitpoints == 0){
			a[j] = ast;
			return;
		}
		j++;
	}
}

void updateAsteroid(astroid_t *p){
	for(uint8_t i = 0;i<100;i++){

		// move bullet if its initialised, ie dmg not 0
		if(p[i].hitpoints != 0){
			p[i].posx += p[i].velx * velfactor;
			p[i].posy += p[i].vely * velfactor;
		}
	}

}

void createBullet(player_t p,bullet_t *b){
	uint8_t speedConst = 2; // Determines the speed, since pacc is always 1

	// Create new bullet depending on player position and direction
	bullet_t newB;
	newB.posx = p.posx;
	newB.posy = p.posy;
	newB.velx = p.accx*speedConst;
	newB.vely = p.accy*speedConst;
	newB.accx = 0;
	newB.accy = 0;

	newB.damagevalue = 1; // Changeable if new weapons are added
	uint16_t j =0;

	// Finds next "DeadSpot" in bullets array
	while(j<100){
		if(b[j].damagevalue == 0){
			b[j] = newB;
			return;
		}
		j++;
	}
}

void updateBullets(bullet_t *p){
	for(uint8_t i = 0;i<100;i++){

		// move bullet if its initialised, ie dmg not 0
		if(p[i].damagevalue != 0){
			p[i].posx += p[i].velx * velfactor;
			p[i].posy += p[i].vely * velfactor;
		}
	}

}

void bulletDeath(bullet_t *b){
	// Sets bulle dmg to 0 allowing the program to overide this cell essentially deleting the bullet
	 (*b).damagevalue = 0;
 	 gotoxy(((*b).posx-(*b).velx*velfactor)/pow(2,14),((*b).posy-(*b).vely*velfactor)/pow(2,14));
	 printf("%c",32);


}

void bulletCollisions(bullet_t *b,astroid_t *a){
	// Checks only live bullets on live astroids
	for(uint8_t i = 0;i<100;i++){
		if(b[i].damagevalue !=0){
			for(uint8_t j =0;j<100;j++){
				if(a[j].hitpoints !=0){
					if(b[i].posx>>14 == a[j].posx>>14 && b[i].posy>>14 == a[j].posy>>14){
						a[j].hitpoints -= b[i].damagevalue;
						bulletDeath(&b[i]);

						// VISUAL PAIN
					 	 gotoxy(a[j].posx>>14,a[j].posy>>14);
					 	 fgcolor(1);
					 	 printf("%c",219);
					 	 fgcolor(7);


						// Kill astroid and bullet add real function later
						if(a[j].hitpoints <= 0){
							gotoxy(a[j].posx>>14,a[j].posy>>14);
							printf("%c",32);
						}
					}
				}
			}
		}
	}


}

void bulletOUB(bullet_t *b){
	// Checks for out of bounds for all bullets
	for(uint8_t i =0; i<100;i++){
		if(b[i].posx>>14 >= 156-1 || b[i].posx>>14 <= 1+1 || b[i].posy>>14 >= 144-1 || b[i].posy>>14 <= 1+1){
			bulletDeath(&b[i]);
		}

	}
}
