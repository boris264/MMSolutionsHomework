#include <stdio.h>
#include <stdint.h>

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit);
int setBit(uint32_t* maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t* maskArr, size_t len, size_t bit);

int main(void)
{
    uint32_t numbers[] = {0, 0, 0, 0, 0, 0};
    setBit(numbers, 6, 0);

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
    putchar('\n');
    
    checkBit(numbers, 6, 0);

    clearBit(numbers, 6, 0);

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }

    putchar('\n');

    return 0;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    for(size_t i = 0; i < nitems; i++)
    {
        maskArr[i] &= ~(1 << bit);
    }
}

int setBit(uint32_t* maskArr, size_t nitems, size_t bit)
{
    for(size_t i = 0; i < nitems; i++)
    {
        maskArr[i] |= 1 << bit;
    }
}

int checkBit(uint32_t* maskArr, size_t len, size_t bit)
{
    for(size_t i = 0; i < len; i++)
    {
        int result = maskArr[i] & (1 << bit) >> bit;
        printf("Bit %ld for mask %d is: %d\n", bit, maskArr[i], result);
    }
}