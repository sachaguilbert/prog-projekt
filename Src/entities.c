#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "entities.h"
#include "ansi.h"
#include "math.h"
#include "graphics.h"
#define velfactor 2


player_t initPlayer(int32_t x, int32_t y){
	player_t player;
	player.posx = x;
	player.posy = y;
	player.dir = 0;
	player.velx = 0;
	player.vely = 0;
	player.accx = 1 << 14;
	player.accy = 0;
	player.radius = 4;
	player.oldDir = player.dir;
	player.oldPos.x = redPixelPos(player).x;
	player.oldPos.y = redPixelPos(player).y;
	player.hitpoints = 10;
	player.level = 1;
	return player;
}
void initAsteroid(astroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy){
	ast->posx = x;
	ast->posy = y;
	ast->velx = dx;
	ast->vely = dy;
	if(ast->style == 1){
		ast->hitpoints = 1;
	}else if(ast->style == 2){
		ast->hitpoints = 5;
	}else{
		ast->hitpoints = 1;
	}
}
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style){
	planet->posx = x;
	planet->posy = y;
	planet->style = style;
}

void planetRandom(planet_t *pla){
    uint32_t planetx = (rand() % 150)<<14;
	uint32_t planety = (rand() % 40)<<14;
	int32_t style = rand() % 3;
	initPlanet(pla, planetx, planety,style);
}

void astroidRandom(astroid_t *a, player_t p){
	astroid_t ast;
	ast.style =(rand() % 2)+ 1;
	uint8_t sel = rand() % 4;
	ast.velx = ((rand() % 3)<<14)*0.1 * p.level;
	ast.vely = ((rand() % 3)<<14)*0.1 * p.level;
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

void updateAsteroid(astroid_t *a){
	for(uint8_t i = 0;i<100;i++){
		// move bullet if its initialised, ie dmg not 0
		if(a[i].hitpoints != 0){
			a[i].posx += (a[i].velx) / velfactor;
			a[i].posy += (a[i].vely)/ velfactor;
		}
	}

}

void astroidOUB(astroid_t *a){
	// Checks for out of bounds for all bullets
		for(uint8_t i =0; i<100;i++){
			if(a[i].hitpoints >0){
				if(a[i].posx>>14 >= 156-1 || a[i].posx>>14 <= 1+1 || a[i].posy>>14 >= 144-1 || a[i].posy>>14 <= 1+1){
					astroidDeath(&a[i]);
			}
		}
	}
}

void astroidDeath(astroid_t *a){
	(*a).hitpoints = 0;
	 switch((*a).style){
		case 1:
			gotoxy(((*a).posx)/pow(2,14),((*a).posy)/pow(2,14));
			printf("%c",32);
			break;
		case 2:
			gotoxy(((*a).posx)/pow(2,14)-1,((*a).posy)/pow(2,14));
			printf("%c%c%c",32,32,32);
			printf("%c%c%c",32,32,32);
			gotoxy(((*a).posx)/pow(2,14),((*a).posy)/pow(2,14)-1);
			printf("%c",32);
			gotoxy(((*a).posx)/pow(2,14),((*a).posy)/pow(2,14)+1);
			printf("%c",32);
			break;
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

bullet_t initBullet()
{
	bullet_t bullet;
	bullet.accx =0;
	bullet.accy =0;
	bullet.damagevalue =0;
	bullet.posx =0;
	bullet.posy =0;
	bullet.velx =0;
	bullet.vely =0;
	return bullet;
}


void updateBullets(bullet_t *b){
	for(uint8_t i = 0;i<100;i++){

		// move bullet if its initialised, ie dmg not 0
		if(b[i].damagevalue != 0){
			b[i].velx += b[i].accx;
			b[i].vely += b[i].accy;
			b[i].posx += b[i].velx / velfactor;
			b[i].posy += b[i].vely / velfactor;
		}
	}

}

void bulletDeath(bullet_t *b){
	// Sets bulle dmg to 0 allowing the program to overide this cell essentially deleting the bullet
	 (*b).damagevalue = 0;
 	 gotoxy(((*b).posx-(*b).velx/velfactor)/pow(2,14),((*b).posy-(*b).vely/velfactor)/pow(2,14));
	 printf("%c",32);


}

void bulletCollisions(bullet_t *b,astroid_t *a,uint32_t *score){
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
						switch(a[i].style){
							case 1:
								gotoxy(a[j].posx>>14,a[j].posy>>14);
								printf("%c",219);
								break;
							case 2:
									gotoxy(a[j].posx>>14,a[j].posy>>14);
									printf("%c",219);
									gotoxy((a[j].posx>>14)+1,a[j].posy>>14);
									printf("%c",219);
									gotoxy((a[j].posx>>14)-1,a[j].posy>>14);
									printf("%c",219);
									gotoxy(a[j].posx>>14,(a[j].posy>>14)+1);
									printf("%c",223);
									gotoxy(a[j].posx>>14,(a[j].posy>>14)-1);
									printf("%c",220);
									break;
								}
					 	 fgcolor(7);

						// Kill astroid and bullet add real function later
						if(a[j].hitpoints <= 0){
							*score += 10*a[j].style;
							astroidDeath(&a[j]);
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
		if(b[i].damagevalue != 0){
			if(b[i].posx>>14 >= 156-1 || b[i].posx>>14 <= 1+1 || b[i].posy>>14 >= 144-1 || b[i].posy>>14 <= 1+1){
				bulletDeath(&b[i]);
			}
		}
	}
}
void playerCollision(player_t *p, astroid_t *a)
{
	vector_t playerVec = {p->posx,p->posy};

	vector_t astroVec[100];
	for(int i = 0; i < 100; i++)
	{
		astroVec[i].x=a[i].posx;
		astroVec[i].y=a[i].posy;
		uint32_t length = len(playerVec,astroVec[i]);
		if(length < p->radius && a[i].hitpoints != 0)
		{
			p->hitpoints -= 1;
			astroidDeath(&a[i]);
		}
	}

}

void updateLevel(player_t *p, uint32_t score)
{
	p->level = (score/100) + 1;
}

int gameOver(player_t p){
	if(p.hitpoints < 10){
		uint8_t stop = 1;
		clrscr();
		uint8_t k = 80;
		uint8_t kk = 20;
		uint8_t prevCenter = returnCenter();
		while(1){
			if(stop){
				gotoxy(k,kk);
				printf("   _____          __  __ ______    ______      ________ _____  \n");
				gotoxy(k,kk+1);
				printf("  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n");
				gotoxy(k,kk+2);
				printf(" | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n");
				gotoxy(k,kk+3);
				printf(" | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / \n");
				gotoxy(k,kk+4);
				printf(" | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n");
				gotoxy(k,kk+5);
				printf("  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\\n");
				stop = 0;
			}
			if(returnCenter()==1 && prevCenter == 0){
				return 0;
			}
			prevCenter = returnCenter();
		}
	}
	return 1;
}
