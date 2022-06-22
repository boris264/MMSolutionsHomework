#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void Conv(int16_t sValue, char *pBuffer);

int main(void)
{
	char result[7];
	Conv(26, result);
	printf("%s\n", result);
	return 0;
}

void Conv(int16_t sValue, char *pBuffer)
{
	for(int i = 0; i < 7; i++)
	{
		pBuffer[i] = ' ';
	}

	pBuffer[0] = sValue >= 0 ? ' ' : '-';

	sValue = abs(sValue);
	uint8_t index = 5;

	while(sValue != 0)
	{
		int16_t digit = sValue % 10;
		sValue /= 10;
		pBuffer[index--] = digit + '0';
	}

	pBuffer[6] = '\0';
}