#include <stdio.h>

int simpleSqrt(int number);

int main(void)
{
    printf("%d\n", simpleSqrt(10));
    return 0;
}

int simpleSqrt(int number)
{
    int i = 1, count = 0;

    while(number > 0)
    {
        number -= i;
        i += 2;
        count++;
    }

    return count;
}