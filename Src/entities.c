#include "entities.h"


void initAsteroid(asteroid_t *ast, int32_t x, int32_t y, int32_t dx, int32_t dy,player_t p){
	ast->posx[0] = x;
	ast->posy[0] = y;
	ast->posx[1] = x+1;
	ast->posy[1] = y;
	ast->posx[2] = x-1;
	ast->posy[2] = y;
	ast->posx[3] = x;
	ast->posy[3] = y+1;
	ast->posx[4] = x;
	ast->posy[4] = y-1;
	ast->velx = dx;
	ast->vely = dy;
	if(ast->style == 1){ //hitpoints scales with player level
		ast->hitpoints = 1+(p.level);
	}else if(ast->style == 2){
		ast->hitpoints = (p.level*3);
	}else{
		ast->hitpoints = 1+(p.level);
	}
}
void initPlanet(planet_t *planet, int32_t x, int32_t y, uint8_t style){
	planet->posx = x;
	planet->posy = y;
	planet->style = style;
}

void planetRandom(planet_t *pla, uint8_t nrOfPla){
	for(int i=0;i<nrOfPla;i++){
		uint32_t planetx = (10 +rand() % (WIN_WIDTH-20))<<14; // spawns the planet at random position
		uint32_t planety = (10 +rand() % (WIN_HEIGHT-20))<<14;
		int32_t style = 1;//rand() % 3;
		initPlanet(&pla[i], planetx, planety,style);
	}
}

void asteroidRandom(asteroid_t *a, player_t p){
	asteroid_t ast;
	ast.style =2;
	uint8_t sel = rand() % 4;
	ast.velx = ((rand() % 3)<<14)>>1 * p.level*3; // 3 is for difference in resolution
	ast.vely = ((rand() % 3)<<14)>>1 * p.level;
    //random places for the asteroid to spawn
	switch(sel){
	case 0:
		initAsteroid(&ast,((rand() % (WIN_WIDTH+5)) - 3)<<14,3<<14,rand() %2 ? ast.velx : -ast.velx,ast.vely,p);
		break;
	case 1:
		initAsteroid(&ast,((rand() % (WIN_WIDTH+5)) - 3)<<14,(WIN_HEIGHT-3)<<14,rand() %2 ? ast.velx : -ast.velx,-ast.vely,p);
		break;
	case 2:
		initAsteroid(&ast,3<<14,((rand() % (WIN_HEIGHT+5)) - 3)<<14,ast.velx,rand() %2 ? ast.vely : -ast.vely,p);
		break;
	case 3:
		initAsteroid(&ast,(WIN_WIDTH - 3)<<14,((rand() % (WIN_HEIGHT+5)) - 3)<<14,-ast.velx,rand() %2 ? ast.vely : -ast.vely,p);
		break;

	}
    //sets the property to the next dead asteroid in the array and spawns it
	for(int i = 0; i < 100; i++)
	{
		if(a[i].hitpoints <= 0)
		{
			a[i] = ast;
			break;
		}
	}

}

void updateAsteroid(asteroid_t *a){
	for(uint8_t i = 0;i<100;i++){
		// move asteroid if its initialised, ie dmg not 0
		if(a[i].hitpoints >= 0){
			if(a[i].style == 2){
				a[i].posx[0] += (a[i].velx) / velfactor;
				a[i].posy[0] += (a[i].vely)/ velfactor;
				a[i].posx[1] = 	a[i].posx[0]+(1<<14);
				a[i].posy[1] = a[i].posy[0];
				a[i].posx[2] = 	a[i].posx[0]-(1<<14);
				a[i].posy[2] = a[i].posy[0];
				a[i].posx[3] = 	a[i].posx[0];
				a[i].posy[3] = a[i].posy[0]+(1<<14);
				a[i].posx[4] = 	a[i].posx[0];
				a[i].posy[4] = a[i].posy[0]-(1<<14);
			}else{
				a[i].posx[0] += (a[i].velx) / velfactor;
				a[i].posy[0] += (a[i].vely)/ velfactor;
			}
			asteroidOB(a);
		}
	}

}

void asteroidHeatSeeking(asteroid_t *a, player_t p)
{
	for(int i = 0; i < 100; i++)
	{
		if (a[i].hitpoints >= 0)
		{
			if(p.posx > a[i].posx[0])
			{
				a[i].velx = (p.level+1) << 13;
			}
			if(p.posx < a[i].posx[0])
			{
				a[i].velx = -(p.level+1) << 13;
			}
			if(p.posy > a[i].posy[0])
			{
				a[i].vely = (p.level+2) << 12;
			}
			if(p.posy < a[i].posy[0])
			{
				a[i].vely = -(p.level+2) << 12;
			}
		}
	}
}

void asteroidOB(asteroid_t *a){
	// Checks for out of bounds for all bullets
		for(uint8_t i =0; i<100;i++){
			if(a[i].hitpoints >0){
				if(a[i].posx[0]>>14 >= WIN_WIDTH-1 || a[i].posx[0]>>14 <= 2 || a[i].posy[0]>>14 >= WIN_HEIGHT-1 || a[i].posy[0]>>14 <= 2){
					asteroidDeath(&a[i]);
			}
		}
	}
}

void asteroidDeath(asteroid_t *a){
	(*a).hitpoints = 0;
    //to diffrent ways to kill the asteroid depending on the style
	 switch((*a).style){
		case 1:
			gotoxy(((*a).posx[0]-(*a).velx)/pow(2,14),((*a).posy[0]-(*a).vely)/pow(2,14));
			printf("%c",32);
			break;
		case 2:
			gotoxy(((*a).posx[0]-(*a).velx)/pow(2,14)-1,((*a).posy[0]-(*a).vely)/pow(2,14));
			printf("%c%c%c",32,32,32);
			printf("%c%c%c",32,32,32);
			gotoxy(((*a).posx[0]-(*a).velx)/pow(2,14),((*a).posy[0]-(*a).vely)/pow(2,14)-1);
			printf("%c",32);
			gotoxy(((*a).posx[0]-(*a).velx)/pow(2,14),((*a).posy[0]-(*a).vely)/pow(2,14)+1);
			printf("%c",32);
			break;
		}

}


void createBullet(player_t p,bullet_t *b){
	uint8_t speedConst = 3; // Determines the speed, since pacc is always 1

	// Create new bullet depending on player position and direction
	bullet_t newB;
	newB.posx = p.posx;
	newB.posy = p.posy;

    //bullets velocity is depending on the player direction.
	switch(p.dir)
	{
	case 0:
		newB.velx = p.velx+p.accx*speedConst;
		newB.vely = p.vely+p.accy*speedConst;
		break;
	case 1:
		newB.velx = p.velx+p.accx*speedConst;
		newB.vely = p.vely-p.accx*speedConst;
		break;
	case 2:
		newB.velx = p.velx+p.accy*speedConst;
		newB.vely = p.vely-p.accx*speedConst;
		break;
	case 3:
		newB.velx = p.velx-p.accx*speedConst;
		newB.vely = p.vely-p.accx*speedConst;
		break;
	case 4:
		newB.velx = p.velx-p.accx*speedConst;
		newB.vely = p.vely+p.accy*speedConst;
		break;
	case 5:
		newB.velx = p.velx-p.accx*speedConst;
		newB.vely = p.vely+p.accx*speedConst;
		break;
	case 6:
		newB.velx = p.velx+p.accy*speedConst;
		newB.vely = p.vely+p.accx*speedConst;
		break;
	case 7:
		newB.velx = p.velx+p.accx*speedConst;
		newB.vely = p.vely+p.accx*speedConst;
		break;
	}


	newB.accx = 0;
	newB.accy = 0;

	newB.damagevalue = p.dmg; // Changeable if new weapons are added
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

void initBullets(bullet_t *b,uint8_t size)
{
	bullet_t bullet;
	bullet.accx =0;
	bullet.accy =0;
	bullet.damagevalue =0;
	bullet.posx =0;
	bullet.posy =0;
	bullet.velx =0;
	bullet.vely =0;
	for(int i = 0; i < size; i++)
	{
				b[i]=bullet;
	}
}


void updateBullets(bullet_t *b, planet_t *pla){
	for(uint8_t i = 0;i<100;i++){

		// move bullet if its initialised, ie dmg not 0
		if(b[i].damagevalue >= 0){
			b[i].velx += b[i].accx;
			b[i].vely += b[i].accy;
			b[i].posx += b[i].velx / velfactor;
			b[i].posy += b[i].vely / velfactor;
		}
	}
	bulletOB(b);
	updateBulletAcc(b,pla,NB_PLANETS);
}

void bulletDeath(bullet_t *b){
	// Sets bulle dmg to 0 allowing the program to overide this cell essentially deleting the bullet
	 (*b).damagevalue = 0;
 	 gotoxy(((*b).posx-(*b).velx/velfactor)/pow(2,14),((*b).posy-(*b).vely/velfactor)/pow(2,14));
	 printf("%c",32);


}

void bulletCollisions(bullet_t *b,asteroid_t *a,player_t *p){
	// Checks only live bullets on live asteroids
	for(uint8_t i = 0;i<100;i++){
		if(b[i].damagevalue >0){
			for(uint8_t j =0;j<100;j++){
				if(a[j].hitpoints > 0){
					switch(a[j].style){
					case 1:
						if(b[i].posx>>14 == a[j].posx[0]>>14 && b[i].posy>>14 == a[j].posy[0]>>14){
							a[j].hitpoints -= b[i].damagevalue;
							bulletDeath(&b[i]);

							// VISUAL PAIN
							 gotoxy(a[j].posx[0]>>14,a[j].posy[0]>>14);
							 fgcolor(1);
							 printf("%c",219);
							 fgcolor(7);
						}
							break;
						case 2:
							for(uint8_t k = 0; k<5;k++){
								if(b[i].posx>>14 == a[j].posx[k]>>14 && b[i].posy>>14 == a[j].posy[k]>>14){
									a[j].hitpoints -= b[i].damagevalue;
									bulletDeath(&b[i]);

									// VISUAL PAIN
									 fgcolor(1);
									 gotoxy((a[j].posx[0]>>14)-1,(a[j].posy[0]>>14));
									 printf("%c%c%c",219,219,219);
									 gotoxy(a[j].posx[0]>>14,(a[j].posy[0]>>14)+1);
									 printf("%c",223);
									 gotoxy(a[j].posx[0]>>14,(a[j].posy[0]>>14)-1);
									 printf("%c",220);
									 fgcolor(7);


									break;
								}
							}

							break;
						}
						if(a[j].hitpoints <= 0){
							p->score += 10*a[j].style;
							switch(a[j].style){
							case 1:
									// VISUAL PAIN
									 gotoxy(a[j].posx[0]>>14,a[j].posy[0]>>14);
									 printf("%c",32);
									break;
								case 2:
											// VISUAL PAIN
									 gotoxy((a[j].posx[0]>>14)-1,(a[j].posy[0]>>14));
									 printf("%c%c%c",32,32,32);
									 gotoxy(a[j].posx[0]>>14,(a[j].posy[0]>>14)+1);
									 printf("%c",32);
						     		 gotoxy(a[j].posx[0]>>14,(a[j].posy[0]>>14)-1);
							    	 printf("%c",32);
											break;
									}
						    int random = rand();
						    if (random % 5 == 1)
						    {
						    	clearAnnouncement();
								createAnnouncement("+1HP!");
						    	p->hitpoints++;
						    }
						    if (random % 10 == 1)
						    {
						    	clearAnnouncement();
						    	createAnnouncement("+1 dmg!");
						    	p->dmg ++;
						    }
						}
					}
				}
			}
		}
	}




void bulletOB(bullet_t *b){
	// Checks for out of bounds for all bullets
	for(uint8_t i =0; i<100;i++){
		if(b[i].damagevalue != 0){
			if(b[i].posx>>14 >= WIN_WIDTH-1 || b[i].posx>>14 <= 1+1 || b[i].posy>>14 >= WIN_HEIGHT-1 || b[i].posy>>14 <= 1+1){
				bulletDeath(&b[i]);
			}
		}
	}
}
void playerCollision(player_t *p, asteroid_t *a)
{
	vector_t playerVec = {p->posx,p->posy};

	vector_t astroVec[100];
	for(int i = 0; i < 100; i++)
	{
		astroVec[i].x=a[i].posx[0];
		astroVec[i].y=a[i].posy[0];
		uint32_t length = len(playerVec,astroVec[i]);
		if(length < p->radius && a[i].hitpoints > 0)
		{
			p->hitpoints -= 1;
			a[i].hitpoints = 0;
			switch(a[i].style){
			case 1:
				// VISUAL PAIN
				gotoxy(a[i].posx[0]>>14,a[i].posy[0]>>14);
				printf("%c",32);
				break;
			case 2:
				// VISUAL PAIN
				gotoxy((a[i].posx[0]>>14)-1,(a[i].posy[0]>>14));
				printf("%c%c%c",32,32,32);
				gotoxy(a[i].posx[0]>>14,(a[i].posy[0]>>14)+1);
				printf("%c",32);
				gotoxy(a[i].posx[0]>>14,(a[i].posy[0]>>14)-1);
				printf("%c",32);
				break;
			}
		}
	}

}

void updateLevel(player_t *p)
{
	p->oldLevel = p->level;
	p->level = (p->score/100) + 1;
	if(p->oldLevel != p->level)
	{
		clearAnnouncement();
		createAnnouncement("LEVEL UP!");
	}
}
