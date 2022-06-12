#include <stdio.h>

unsigned sumArrayDigits(const int* arr, size_t n);
unsigned sumDigits(int number);

int main(void)
{
    int arr[] = {12, 34, 5, 70};
    
    printf("%d\n", sumArrayDigits(arr, 4));
    return 0;
}

unsigned sumArrayDigits(const int* arr, size_t n)
{
    unsigned sum = 0;

    for(size_t i = 0; i < n; i++)
    {
        sum += sumDigits(arr[i]);
    }

    return sum;
}

unsigned sumDigits(int number)
{
    unsigned sum = 0;

    while(number != 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}