#include <stdio.h>

void convertToBin(int number);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    convertToBin(n);

    return 0;
}

void convertToBin(int number)
{
    int bits[32];

    for(int i = 0; i < sizeof(int) * 8; i++)
    {
        bits[sizeof(int) * 8 - 1 - i] = (number & (1 << i)) >> i;
    }
   
    for(int i = 0; i < sizeof(int) * 8; i++)
    {
        printf("%d", bits[i]);
    }

    putchar('\n');
}