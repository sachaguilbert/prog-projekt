#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include "entities.h"

int main(void)
{
	uart_init(115200);
	clrscr();
	drawGameStart();
	while(1){}
}
