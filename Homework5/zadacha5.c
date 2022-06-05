#include <stdio.h>
#include <stdint.h>

unsigned onesCount(uint64_t mask);

int main(void)
{
    uint64_t number;

    printf("Enter a number: ");
    scanf("%ld", &number);

    printf("The number %ld has %u bits set to one\n", number,onesCount(number));
    return 0;
}

unsigned onesCount(uint64_t mask)
{
    unsigned count = 0;

    for(uint64_t i = 0; i < sizeof(mask) * 8; i++)
    {
        int result = (mask & (1 << i)) >> i;

        if(result == 1)
        {
            count++;
        }
    }

    return count;
}