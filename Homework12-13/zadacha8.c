#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void Add(const char* p1, const char* p2, char* result);
unsigned getDigitCount(int number);

int main(void)
{
	char result[12];
	memset(result, 0, 12);

	Add("123", "2", result);
	printf("%s\n", result);
	return 0;
}

void Add(const char* p1, const char* p2, char* result)
{
	int p1Num = atoi(p1);
	int p2Num = atoi(p2);

	int res = p1Num + p2Num;

	result[0] = res >= 0 ? ' ' : '-';
	
	int digits[getDigitCount(res)];
	int index = 0;

	while(res != 0 )
	{
		digits[index] = res % 10;
		res /= 10;
		index++;
	}

	for(int i = sizeof(digits) - 1; i >= 0; i--)
	{
		result[sizeof(digits) - 1 - i] = digits[i] + '0';
	}

	result[sizeof(digits)] = 0;
}

unsigned getDigitCount(int number)
{
	unsigned count = 0;

	while(number != 0)
	{
		number /= 10;
		count++;
	}

	return count;
}