#ifndef GRAVITY_H_
#define GRAVITY_H_

/* Includes ------------------------------------------------------------------*/
#include "stdio.h"
#include "stdint.h"
#include "entities.h"
#include "window.h"
#include "math.h"

/* Exported functions ------------------------------------------------------- */
void updateBulletAcc(bullet_t *b, planet_t *p,uint8_t arrsize);
#endif /* GRAVITY_H_ */
