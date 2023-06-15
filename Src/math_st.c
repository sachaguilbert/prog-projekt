#include "math_st.h"

signed short sinLUT(int32_t angel){
	while(angel >= 512){angel-=512;}
	if(angel<0){
		return -SIN[-angel];
	}

	return SIN[angel];
}

signed short cosLUT(int32_t angel){
	return sinLUT(angel+128);
}
void stm_sleep(uint32_t t)
{
	const uint64_t clock = 640000;
	uint64_t tick = (clock*t*5)/1000;
	for (int i = 0; i < tick; i++)
	{
		__asm__ __volatile__("nop");
	}

}

void rotateVector(vector_t *v, int16_t a)
{
	int64_t xcos = v->x*cosLUT(a);
	int64_t ysin = v->y*sinLUT(a);
	int64_t xsin = v->x*sinLUT(a);
	int64_t ycos = v->y*cosLUT(a);
	v->x = (xcos - ysin) >> 14;
	v->y = (xsin + ycos) >> 14;
}



