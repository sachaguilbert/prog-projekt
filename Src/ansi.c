#define ESC 0x1B
#include "stdio.h"
#include "stdint.h"

void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr(){
	printf("%c[2J",ESC);
}

void clreol(){
	printf("%c[2K",ESC);

}

void gotoxy(uint8_t x,uint8_t y){
	printf("%c[%u;%uH",ESC,y,x);

}

void underline(uint8_t on){
	if(on){
		printf("%c[04;04;....;04m",ESC);
	}else{
		printf("%c[24;24;....;24m",ESC);

	}

}

void blink(uint8_t on){
	if(on){
		printf("%c[05;05;....;05m",ESC);
	}else{
		printf("%c[25;25;....;25m",ESC);

	}
}

void reverse(uint8_t on){
	if(on){
		printf("%c[07;07;....;07m",ESC);
	}else{
		printf("%c[27;27;....;27m",ESC);

	}

}

// p1,p2 as (x,y)
void window(uint8_t p1[2],uint8_t p2[2],char title[], uint8_t style){
	uint8_t i,ver,hor,space,TL,TR,BL,BR,CL,CR;


	switch(style){
	case 1: ;
		ver = 179; hor = 196;space =32; TL = 218; TR = 195;BL=192;BR=217;CL=180;CR=181;
		break;
	case 2:
		ver = 186; hor = 205;space =32; TL = 201; TR = 187;BL=192;BR=188;CL=185;CR=204;
		break;
	}

	color(7,0);
			// TOP LEFT
			gotoxy(p1[0],p1[1]);
			printf("%c",TL);
			gotoxy(p1[0]+1,p1[1]);
			printf("%c",CL);

			// TOP RIGTH
			gotoxy(p2[0]-1,p1[1]);
			printf("%c",CR);
			gotoxy(p2[0],p1[1]);
			printf("%c",TR);

			// TITLE

			gotoxy(p1[0]+2,p1[1]);
			printf("%c",space);


			int j = 0;
			for(i=p1[0]+3;i<p2[0]-1;i++){
				gotoxy(i,p1[1]);
				if(title[j] != '\0'){
					printf("%c",title[j]);
					j++;
				}else{
					printf("%c",space);
				}
			}



			// RIGTH EDGE
			for(i=p1[1]+1;i<p2[1];i++){
				gotoxy(p2[0],i);
				printf("%c",ver);
			}
			// LEFT EDGE
			for(i=p1[1]+1;i<p2[1];i++){
				gotoxy(p1[0],i);
				printf("%c",ver);
			}

			// BOTTOM EDGE
			gotoxy(p2[0],p2[1]);
			printf("%c",BR);
			gotoxy(p1[0],p2[1]);
			printf("%c",BL);
			for(i=p1[0]+1;i<p2[0];i++){
				gotoxy(i,p2[1]);
				printf("%c",hor);
			}

}
void gameWindow(uint16_t p1[2],uint16_t p2[2], uint8_t style){
	uint16_t i,ver,hor,TL,TR,BL,BR;


	switch(style){
	case 1: ;
		ver = 179; hor = 196;TL = 218; TR = 191;BL=192;BR=217;
		break;
	case 2:
		ver = 186; hor = 205; TL = 201; TR = 187;BL=200;BR=188;
		break;
	}

			color(7,0);
			// TOP LEFT
			gotoxy(p1[0],p1[1]);
			printf("%c",TL);


			// TOP RIGTH
			gotoxy(p2[0],p1[1]);
			printf("%c",TR);

			// TOP
			for(i=p1[0]+1;i<p2[0];i++){
				gotoxy(i,p1[1]);
				printf("%c",hor);
			}

			// RIGTH EDGE
			for(i=p1[1]+1;i<p2[1];i++){
				gotoxy(p2[0],i);
				printf("%c",ver);
			}
			// LEFT EDGE
			for(i=p1[1]+1;i<p2[1];i++){
				gotoxy(p1[0],i);
				printf("%c",ver);
			}

			// BOTTOM EDGE
			gotoxy(p2[0],p2[1]);
			printf("%c",BR);
			gotoxy(p1[0],p2[1]);
			printf("%c",BL);
			for(i=p1[0]+1;i<p2[0];i++){
				gotoxy(i,p2[1]);
				printf("%c",hor);
			}


}




