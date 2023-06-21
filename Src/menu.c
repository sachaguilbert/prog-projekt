#include "menu.h"

void mainMenu(){
	clrscr();
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
	uint16_t p1[2] = {WIN_WIDTH/2 - 10,20};
	uint16_t p2[2] = {WIN_WIDTH/2 + 70,50};
	gameWindow(p1,p2,2);
	gotoxy(WIN_WIDTH/2+27,20);
	printf("HELP");
	uint8_t prevCent = returnCenter();
	gotoxy(WIN_WIDTH/2 - 7,25);
	printf("Controls:\n");
	gotoxy(WIN_WIDTH/2 - 7,27);
	printf("Use the joystick to control the spaceship movement and the buttons to shoot\n");
	gotoxy(WIN_WIDTH/2 - 7,28);
	printf("bullets at the asteroids. When hitting and destroying asteroid you will get\n");
	gotoxy(WIN_WIDTH/2 - 7,29);
	printf("a random power-up, either +1 HP or +1 DAMAGE.\n");
	gotoxy(WIN_WIDTH/2 - 7,33);
	printf("Goal of the game:\n");
	gotoxy(WIN_WIDTH/2 - 7,35);
	printf("Shoot asteroids to increase your score. If you beat your high-score it will\n");
	gotoxy(WIN_WIDTH/2 - 7,36);
	printf("be updated. Getting hit by the asteroids will cost you 1 HP and when you\n");
	gotoxy(WIN_WIDTH/2 - 7,37);
	printf("run out, it's GAME OVER.\n");
	uint16_t p5[2] = {WIN_WIDTH/2 + 17,39};
	uint16_t p6[2] = {WIN_WIDTH/2 + 42,41};
	gameWindow(p5,p6,2);
	gotoxy(WIN_WIDTH/2 + 27,40);
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
		uint16_t p1[2] = {WIN_WIDTH/2 + 17,29};
		uint16_t p2[2] = {WIN_WIDTH/2 + 42,31};
		gameWindow(p1,p2,2);
		uint16_t p5[2] = {WIN_WIDTH/2 + 17,39};
		uint16_t p6[2] = {WIN_WIDTH/2 + 42,41};
		gameWindow(p5,p6,1);
	}else if(option == 1 && action == 1){
		uint16_t p1[2] = {WIN_WIDTH/2 + 17,29};
		uint16_t p2[2] = {WIN_WIDTH/2 + 42,31};
		gameWindow(p1,p2,1);
		uint16_t p5[2] = {WIN_WIDTH/2 + 17,39};
		uint16_t p6[2] = {WIN_WIDTH/2 + 42,41};
		gameWindow(p5,p6,2);
	}
}
void drawStart(){
	clrscr();
	uint8_t k = WIN_WIDTH/2 - 25;
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
	uint16_t p1[2] = {WIN_WIDTH/2 - 10,20};
	uint16_t p2[2] = {WIN_WIDTH/2 + 70,50};
	gameWindow(p1,p2,2);
	gotoxy(WIN_WIDTH/2 + 27,20);
	printf("MENU");
	gotoxy(WIN_WIDTH/2 + 27,30);
	printf("PLAY");
	//gotoxy(111,35);
	//printf("SETTINGS");
	gotoxy(WIN_WIDTH/2 + 22,40);
	printf("HELP AND CONTROLS");
}

void page(){
	initPins();
	uint8_t pagenr = 0;
	uint8_t centerx = WIN_WIDTH / 2 - 20;
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
		uint8_t k = WIN_WIDTH/2;
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

void bossKey()
{
	// Limits inputs to 3 per tick
	uint8_t i = 0;
	while(uart_get_count()>0 && i<3){
		uint8_t input = get_keyboard_input();
		if(input == 98){
			NVIC_DisableIRQ(TIM1_BRK_TIM15_IRQn);
			clrscr();
			gotoxy(1,1);
		    int rows = 40;    // Number of rows in the Excel sheet
		    int columns = 15; // Number of columns in the Excel sheet

		    // ASCII art for the Excel sheet
		    printf(" ");
		    for(int i = 1; i<columns;i++){
		    printf("_________");
		    }
		    printf("\n|");
		    for(int i = 1; i<columns;i++){
		    printf("         ");
		    }
		    printf("|\n");
		    // Print column headers (A, B, C, ...)
		    printf("|      ");
		    for (int i = 0; i < columns; i++) {
		        printf("|   %c   ", 'A' + i);
		    }
		    printf("|\n");

		    // Print horizontal separator
		    printf("|______");
		    for (int i = 0; i < columns; i++) {
		        printf("|_______");
		    }
		    printf("|\n");

		    // Print rows with cell values
		    for (int row = 1; row <= rows; row++) {
		        printf("|   %2d ", row);

		        for (int col = 0; col < columns; col++) {
		            printf("|   %3u ", rand() %999);
		        }
		        printf("|\n");
		    }

		    // Print bottom border
		    printf("|______");
		    for (int i = 0; i < columns; i++) {
		        printf("|_______");
		    }
		    printf("|\n");
			while(1){

				if(uart_get_count()>0){

					if(get_keyboard_input() == 98){
						clrscr();
						break;
					}
				}
			}
			NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

		}
		i++;
	}
	uart_clear();
}
