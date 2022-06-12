#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word); 

int main(void)
{
    uint16_t n;
    printf("Enter a number: ");
    scanf("%hu", &n);
    swapBytes(&n);

    printf("%u\n", n);
    return 0;
}

void swapBytes(uint16_t* word)
{
    uint16_t firstByte = 0;
    uint16_t secondByte = 0;
    uint16_t newWord = 0;

    for(uint16_t i = 0; i < 8; i++)
    {
        firstByte ^= *word & (1 << i);
        secondByte ^= *word & (1 << (i + 8));
    }
    
    newWord ^= secondByte;
    newWord ^= firstByte << 8;
    *word = newWord;
}