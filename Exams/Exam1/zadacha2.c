#include <stdio.h>
#include <stdint.h>

void flipOddBits(uint64_t* mask);
unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void mirrorBits(uint16_t* mask);

int main(void)
{
    uint64_t mask = 0b0000000000000000000000000000000000000000000000000000000000000000UL;
    uint16_t mask16 = 0b1111111100000000;

    printf("%u\n", bitsNCount(6543408UL, 653778787u, (uint16_t)65200, (uint8_t)253));
    
    flipOddBits(&mask);
    mirrorBits(&mask16);

    return 0;
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
    unsigned bitsCount = 0;

    for(uint64_t i = 0; i < sizeof(mask1) * 8; i++)
    {
        uint64_t result = (mask1 & (1 << i)) >> i;

        if(result == 1)
        {
            bitsCount++;
        }
    }

    for(uint32_t i = 0; i < sizeof(mask2) * 8; i++)
    {
        uint32_t result = (mask2 & (1 << i)) >> i;

        if(result == 1)
        {
            bitsCount++;
        }
    }

    for(uint16_t i = 0; i < sizeof(mask3) * 8; i++)
    {
        uint16_t result = (mask3 & (1 << i)) >> i;

        if(result == 1)
        {
            bitsCount++;
        }
    }

    for(uint8_t i = 0; i < sizeof(mask4) * 8; i++)
    {
        uint8_t result = (mask4 & (1 << i)) >> i;

        if(result == 1)
        {
            bitsCount++;
        }
    }

    return bitsCount;
}

void flipOddBits(uint64_t* mask)
{
    uint64_t initialMaskValue = *mask;

    for(uint64_t i = 0; i < sizeof(mask) * 8; i++)
    {
        uint64_t m = (1UL << i);

        if(i % 2 != 0)
        {
            *mask  =  *mask ^ m;
        }
    }

    printf("Flipped value of %lu = %lu\n", initialMaskValue, *mask);
}

void mirrorBits(uint16_t* mask)
{
    uint16_t initialMask = *mask;

    for(uint16_t i = 0; i < sizeof(*mask) * 8; i++)
    {
        uint16_t m = 1 << i;
        *mask ^= m;
    }

    printf("The value of %hu with flipped bits is: %hu\n", initialMask, *mask);
}