#ifndef _MATH_ST_H_
#define _MATH_ST_H_

/* Includes ------------------------------------------------------------------*/
#include "LUTsin.h"
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
typedef struct {
	int32_t x, y;
} vector_t;


/* Exported functions ------------------------------------------------------- */
signed short sinLUT(int32_t angel);
signed short cosLUT(int32_t angel);
void stm_sleep(uint32_t t);
void rotateVector(vector_t *v, int16_t a);

#endif /* _30010_IO_H_ */
