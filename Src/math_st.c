#include "math_st.h"

signed short sinLUT(int x) //512 = 360 degrees, to convert degrees to 512 format: x*512/360
{
	uint8_t negative = 0;
	if(x < 0) {
		negative = 1;
		x = -x;
	}
	x %= 512;
	if (negative) {
		return -(SIN[x]);
	} else {
		return SIN[x];
	}
}

signed short cosLUT(int x)//512 = 360 degrees, to convert degrees to 512 format: x*512/360
{
	x = x < 0 ? -x : x;
	x+=128;
	x %= 512;
	return SIN[x];
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
