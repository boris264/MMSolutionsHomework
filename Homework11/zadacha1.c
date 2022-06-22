#include <stdio.h>

#define MAX(x,y,z) ((x) > (y) && (x) > (z)) ? x : ((y) > (x) && (y) > (z) ? y : z)
#define MIN(x,y,z) ((x) < (y) && (x) < (z)) ? x : ((y) < (x) && (y) < (z) ? y : z)
#define SETBIT(mask, bit) (mask) | (1 << (bit))
#define CLEARBIT(mask, bit) (mask) & ~(1 << (bit))
#define INVERSEBIT(mask, bit) (mask) ^ (1 << (bit))
#define CHECKBIT(mask, bit) ((mask) & (1 << (bit))) >> (bit)

int main(void)
{
    int max = MAX(153,32,5);
    int min = MIN(153,32,5);
    int setbit = SETBIT(0, 1);
    int clearbit = CLEARBIT(2, 1);
    int inversebit = INVERSEBIT(0, 1);
    int checkbit = CHECKBIT(1, 1);

    printf("%d\n", max);
    printf("%d\n", min);
    printf("%d\n", setbit);
    printf("%d\n", clearbit);
    printf("%d\n", inversebit);
    printf("%d\n", checkbit);
    return 0;
}