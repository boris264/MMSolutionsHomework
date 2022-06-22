#include <stdio.h>
#include <math.h>
#include <stdint.h>

unsigned char CheckBit(unsigned int uValue);

int main(void)
{
	for(uint16_t i = 1; i < UINT16_MAX / 2; i *= 2)
	{
		printf("%d\n", CheckBit(i));
	}

	return 0;
}

unsigned char CheckBit(unsigned int uValue)
{
	double result = log2(uValue);

	return fabs(ceil(result) - result) < 0.0001 ? 1 : 0;  
}
