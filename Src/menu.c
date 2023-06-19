#include "menu.h"

void mainMenu(){
	initPins();
	drawStart();
	int8_t option = 0;
	uint8_t prevUp = returnUp();
	uint8_t prevDown = returnDown();
	uint8_t prevCent = returnCenter();
	uint8_t action = 1;

	while(1){
		if(returnUp()==1 && prevUp == 0){
			option -= 1;
			action = 1;
		} else if(returnDown()==1 && prevDown == 0){
			option += 1;
			action = 1;
		}
		prevUp = returnUp();
		prevDown = returnDown();
		if(option<0){
			option = 1;
		}else if(option>1){
			option = 0;
		}
		//draw option boxes
		drawBoxes(option, action);
		if(returnCenter() == 1 && prevCent == 0){
			if(option == 0){break;}
			if(option == 1){helpMenu();drawStart();}
		}
		prevCent = returnCenter();
	}
	clrscr();
}

void helpMenu(){
	clrscr();
	uint16_t p1[2] = {75,20};
	uint16_t p2[2] = {155,50};
	gameWindow(p1,p2,2);
	gotoxy(113,20);
	printf("HELP");
	uint8_t prevCent = returnCenter();
	gotoxy(108,26);
	printf("This is the menu\n");
	gotoxy(108,27);
	printf("that shows all info\n");
	gotoxy(108,28);
	printf("concerning how to\n");
	gotoxy(108,29);
	printf("play the game.");
	uint16_t p5[2] = {105,39};
	uint16_t p6[2] = {125,41};
	gameWindow(p5,p6,2);
	gotoxy(112,40);
	fgcolor(1);
	printf("RETURN");
	fgcolor(7);
	while(1){
		if(returnCenter() == 1 && prevCent == 0){
			break;
		}
		prevCent = returnCenter();
	}
}

void drawBoxes(uint8_t option, uint8_t action){
	//This bit of code is long as fuck so i removed it from the main menu function:
	if(option == 0 && action == 1){
		uint16_t p1[2] = {105,29};
		uint16_t p2[2] = {125,31};
		gameWindow(p1,p2,2);
		uint16_t p5[2] = {105,39};
		uint16_t p6[2] = {125,41};
		gameWindow(p5,p6,1);
	}else if(option == 1 && action == 1){
		uint16_t p1[2] = {105,29};
		uint16_t p2[2] = {125,31};
		gameWindow(p1,p2,1);
		uint16_t p5[2] = {105,39};
		uint16_t p6[2] = {125,41};
		gameWindow(p5,p6,2);
	}
}
void drawStart(){
	clrscr();
	uint8_t k = 60;
	uint8_t kk = 5;
	gotoxy(k,kk);
	printf("            _____ _______ _____            _         _____ _    _         _____  _____ _____          _   _ \n");
	gotoxy(k,kk+1);
	printf("     /\\    / ____|__   __|  __ \\     /\\   | |       / ____| |  | |  /\\   |  __ \\|  __ \\_   _|   /\\   | \\ | |\n");
	gotoxy(k,kk+2);
	printf("    /  \\  | (___    | |  | |__) |   /  \\  | |      | |  __| |  | | /  \\  | |__) | |  | || |    /  \\  |  \\| |\n");
	gotoxy(k,kk+3);
	printf("   / /\\ \\  \\___ \\   | |  |  _  /   / /\\ \\ | |      | | |_ | |  | |/ /\\ \\ |  _  /| |  | || |   / /\\ \\ | . ` |\n");
	gotoxy(k,kk+4);
	printf("  / ____ \\ ____) |  | |  | | \\ \\  / ____ \\| |____  | |__| | |__| / ____ \\| | \\ \\| |__| || |_ / ____ \\| |\\  |\n");
	gotoxy(k,kk+5);
	printf(" /_/    \\_\\_____/   |_|  |_|  \\_\\/_/    \\_\\______|  \\_____|\\____/_/    \\_\\_|  \\_\\_____/_____/_/    \\_\\_| \\_|\n");
	uint16_t p1[2] = {75,20};
	uint16_t p2[2] = {155,50};
	gameWindow(p1,p2,2);
	gotoxy(113,20);
	printf("MENU");
	gotoxy(113,30);
	printf("PLAY");
	//gotoxy(111,35);
	//printf("SETTINGS");
	gotoxy(107,40);
	printf("HELP AND CONTROLS");
}

void page(){
	initPins();
	uint8_t pagenr = 0;
	uint8_t centerx = 75;
	uint8_t centery = 10;
	uint8_t next = 1;
	uint8_t prevCenter = returnCenter();
	while(1){
		if(returnCenter()==1 && prevCenter == 0){
			pagenr += 1;
			next = 1;
		}
		prevCenter = returnCenter();

		if(pagenr == 0 && next == 1){
			gotoxy(centerx,1+centery);
			printf("Once upon a time, in a galaxy far, far away, humanity had conquered the vastness of space and\n");
			gotoxy(centerx,2+centery);
			printf("established colonies on various planets and moons across the galaxy. As the colonies\n");
			gotoxy(centerx,3+centery);
			printf("thrived and expanded, they faced a recurring threat: asteroids hurtling through space,\n");
			gotoxy(centerx,4+centery);
			printf("posing a danger to both the settlements and the delicate balance of the cosmos.");
			next = 0;
		}
		if(pagenr == 1 && next == 1){
			clrscr();
			gotoxy(centerx,1+centery);
			printf("In response to this peril, a team of brilliant engineers and scientists came together to design\n");
			gotoxy(centerx,2+centery);
			printf("a revolutionary spacecraft known as the Astral Guardian. Their mission was to protect the\n");
			gotoxy(centerx,3+centery);
			printf("colonies from the destructive force of asteroids and maintain the safety of interstellar travel\n");
			gotoxy(centerx,4+centery);
			printf("routes.");
			next = 0;
		}
		if(pagenr == 2 && next == 1){
			clrscr();
			gotoxy(centerx,1+centery);
			printf("At the heart of the ship was a formidable arsenal of advanced weaponry. The Astral Guardian\n");
			gotoxy(centerx,2+centery);
			printf("was armed with an array of energy-based cannons, plasma projectors, and guided missiles,\n");
			gotoxy(centerx,3+centery);
			printf("all specifically designed to obliterate incoming asteroids before they could pose a threat to\n");
			gotoxy(centerx,4+centery);
			printf("the colonies. Its targeting systems were so precise that it could neutralize even the smallest\n");
			gotoxy(centerx,5+centery);
			printf("of space rocks without causing collateral damage.");
			next = 0;
		}
		if(pagenr == 3	 && next == 1){
			clrscr();
			break;
		}
	}
}


int gameOver(player_t *p){
	if(p->hitpoints < 1){
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
				uint16_t hs = memRead(0); //Highscore stored in flash memory
				if(p->score > hs){
					uint16_t data[1] = {p->score};
					uint8_t sizeofarr = sizeof(data)/sizeof(data[0]);
					memWrite(data,sizeofarr); //Update flash memory with new score
				}
				return 0;
			}
			prevCenter = returnCenter();
		}
	}
	return 1;
}
