#include <stdio.h>

void VMirror(unsigned char* pImage);
unsigned char  swapBits(unsigned char var);

int main(void)
{
	unsigned char image[] = {0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00};

	VMirror(image);

	for(int i = 0; image[i] != 0; i++)
	{
		printf("%X ", image[i]);
	}

	putchar('\n');
	return 0;
}

void VMirror(unsigned char* pImage)
{
	for(int i = 0; pImage[i] != 0; i++)
	{
		pImage[i] = swapBits(pImage[i]);
	}
}

unsigned char swapBits(unsigned char var)
{
	unsigned char newNumber = 0;

	for(int i = sizeof(var) * 7; i >= 0; i--)
	{
		newNumber |= ((var & (1 << i)) >> i) << (sizeof(var) * 7 - i);
	}

	return newNumber;
}