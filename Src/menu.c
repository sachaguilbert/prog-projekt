#include "menu.h"

void mainMenu(){
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
		if(returnCenter() == 1 && prevCent == 0){
			if(option == 0){breaak = 1;}
			if(option == 1){/*settings menu*/}
			if(option == 2){/*help menu*/}
		}
		prevCent = returnCenter();
	}
	clrscr();
}
