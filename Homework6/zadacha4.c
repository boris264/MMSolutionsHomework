#include <stdio.h>
#include <stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...);
unsigned bits(int mask);

int main(void)
{
    printf("%d\n", bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111));
    return 0;
}

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...)
{
    unsigned total = 0;

    va_list items;
    va_start(items, bitscnt);
    
    for(int i = 0; i < count; i++)
    {
        int item = va_arg(items, int);
        
        if(bits(item) == bitscnt)
        {
            total++;
        }
    }

    return total;
}

unsigned bits(int mask)
{
    unsigned count = 0;

    for(int i = 0; i < sizeof(mask) * 8; i++)
    {
        count += (mask & (1 << i)) >> i;
    }

    return count;
}