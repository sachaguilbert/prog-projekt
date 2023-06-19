#include "LCD.h"


uint8_t buffer[512];
uint8_t flag =0;
uint8_t thing =0;

void lcd_write_string(char str[],uint32_t loc){
	int i,j;
	memset(buffer,0x00,512);

	for(i=0;i<strlen(str);i++){
		uint8_t ch = str[i]-0x20;
		for(j=0;j<5;j++){
			buffer[loc+j] = character_data[ch][j];
		}
		loc +=5;
	}

	lcd_push_buffer(buffer);
}

void lcd_scoreboard(player_t p){
	char scoreBoard[520];
	uint16_t hs = memRead(0);
	sprintf(scoreBoard,"LEVEL: %02u HIGHSCORE: %04u HP: %02u        SCORE: %04u",p.level,hs,p.hitpoints,p.score);
	lcd_write_string(scoreBoard,0);

}


void lcd_update(){
	if(flag){
		thing++;
		flag =0;
	}

	if(thing >= 5){
		uint8_t temp[512];
		int i;

		for (i = 0; i < 512; i++) {
		        temp[i] = buffer[i];
		    }


		for(i=1;i<128;i++){
			buffer[i] = temp[i-1];
		}
		buffer[0] = temp[127];

		for(i=128;i<256;i++){
			buffer[i] = temp[i-1];
		}
		buffer[128] = temp[255];


		lcd_push_buffer(buffer);
		thing = 0;
	}
}
