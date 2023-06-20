#include "game.h"

void gameInit()
{
	uart_init(921600);
	lcd_init();
	ADCSetup();
	clrscr();
	page();
	LEDSetup();
	tim15Setup();
}

void updatePlayer(player_t *p)
{
	deletePlayer(*p);
	update_player_pos(p);
	drawPlayer(*p);
}
void updateEntities(player_t *p,bullet_t *bullets, planet_t *planet, asteroid_t *asteroids)
{
	deletePlayer(*p);
	update_player_pos(p);
	drawPlayer(*p);
	updateBullets(bullets,planet);
	asteroidHeatSeeking(asteroids, *p);
	updateAsteroid(asteroids);
}

void drawEntities(asteroid_t *asteroids, bullet_t *bullets, planet_t *planet, player_t p)
{
	drawAsteroids(asteroids);
	drawBullets(bullets);
}
