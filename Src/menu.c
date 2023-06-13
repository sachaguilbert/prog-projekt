#include "menu.h"

void mainMenu(){
	initPins();
	drawStart();
	uint8_t breaak = 0;
	int8_t option = 0;
	uint8_t prevUp = returnUp();
	uint8_t prevDown = returnDown();
	uint8_t prevCent = returnCenter();
	uint8_t action = 1;
	while(!breaak){
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
			option = 2;
		}else if(option>2){
			option = 0;
		}
		//draw option boxes
		drawBoxes(option, action);
		if(returnCenter() == 1 && prevCent == 0){
			if(option == 0){breaak = 1;}
			if(option == 1){settingsMenu();drawStart();}
			if(option == 2){helpMenu();drawStart();}
		}
		prevCent = returnCenter();
		gotoxy(0,10);
		printf("Inside main menu");
	}
	clrscr();
}

void settingsMenu(){
	clrscr();
	uint16_t p1[2] = {75,10};
	uint16_t p2[2] = {155,50};
	gameWindow(p1,p2,2);
	gotoxy(111,10);
	printf("SETTINGS");
		uint8_t prevCent = returnCenter();
	for(int i=105;i<125+1;i++){
		for(int j=19;j<41+1;j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
	gotoxy(108,20);
	printf("This is the menu\n");
	gotoxy(108,21);
	printf("that shows all info\n");
	gotoxy(108,22);
	printf("concerning skins and\n");
	gotoxy(108,23);
	printf("player customization");
	uint16_t p5[2] = {105,39};
	uint16_t p6[2] = {125,41};
	gameWindow(p5,p6,2);
	gotoxy(112,40);
	fgcolor(1);
	printf("RETURN");
	fgcolor(7);
	while(1){
		gotoxy(0,10);
		printf("Inside settings menu");
		if(returnCenter() == 1 && prevCent == 0){
			break;
		}
		prevCent = returnCenter();
	}
}

void helpMenu(){
	clrscr();
	uint16_t p1[2] = {75,10};
	uint16_t p2[2] = {155,50};
	gameWindow(p1,p2,2);
	gotoxy(113,10);
	printf("HELP");
	uint8_t prevCent = returnCenter();
	gotoxy(108,20);
	printf("This is the menu\n");
	gotoxy(108,21);
	printf("that shows all info\n");
	gotoxy(108,22);
	printf("concerning how to\n");
	gotoxy(108,23);
	printf("play the game");
	uint16_t p5[2] = {105,39};
	uint16_t p6[2] = {125,41};
	gameWindow(p5,p6,2);
	gotoxy(112,40);
	fgcolor(1);
	printf("RETURN");
	fgcolor(7);
	while(1){
		gotoxy(0,10);
		printf("Inside help menu");
		if(returnCenter() == 1 && prevCent == 0){
			break;
		}
		prevCent = returnCenter();
	}
}

void drawBoxes(uint8_t option, uint8_t action){
	//This bit of code is long as fuck so i removed it from the main menu function:
	if(option == 0 && action == 1){
		uint16_t p1[2] = {105,19};
		uint16_t p2[2] = {125,21};
		gameWindow(p1,p2,2);
		uint16_t p3[2] = {105,29};
		uint16_t p4[2] = {125,31};
		gameWindow(p3,p4,1);
		uint16_t p5[2] = {105,39};
		uint16_t p6[2] = {125,41};
		gameWindow(p5,p6,1);
	}else if(option == 1 && action == 1){
		uint16_t p1[2] = {105,19};
		uint16_t p2[2] = {125,21};
		gameWindow(p1,p2,1);
		uint16_t p3[2] = {105,29};
		uint16_t p4[2] = {125,31};
		gameWindow(p3,p4,2);
		uint16_t p5[2] = {105,39};
		uint16_t p6[2] = {125,41};
		gameWindow(p5,p6,1);
	}else if(option == 2 && action == 1){
		uint16_t p1[2] = {105,19};
		uint16_t p2[2] = {125,21};
		gameWindow(p1,p2,1);
		uint16_t p3[2] = {105,29};
		uint16_t p4[2] = {125,31};
		gameWindow(p3,p4,1);
		uint16_t p5[2] = {105,39};
		uint16_t p6[2] = {125,41};
		gameWindow(p5,p6,2);
	}
}
void drawStart(){
	clrscr();
	uint16_t p1[2] = {75,10};
	uint16_t p2[2] = {155,50};
	gameWindow(p1,p2,2);
	gotoxy(113,10);
	printf("MENU");
	gotoxy(113,20);
	printf("PLAY");
	gotoxy(111,30);
	printf("SETTINGS");
	gotoxy(107,40);
	printf("HELP AND CONTROLS");
}
