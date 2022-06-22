#include <stdio.h>

void Reverse(char* ptr);

int main(void)
{
	Reverse("This is a test");
	return 0;
}

void Reverse(char* ptr)
{
	int length = 0;

	for(int i = 0; ptr[i] != '\0'; i++)
	{
		length++;
	}

	char newString[length + 1];

	for(int i = 0; i < length; i++)
	{
		newString[i] = ptr[length - 1 - i];
	}

	newString[length] = '\0';

	printf("%s\n", newString);
}