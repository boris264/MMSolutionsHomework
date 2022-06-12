#include <stdio.h>

void map(int* array, size_t n, int (*func)(int));
int divideNum(int);

int main(void)
{
    int arr[] = {10, 2, 4, 423, 5662, 4};
    map(arr, 6, divideNum);

    for(int i = 0; i < 6; i++)
    {
        printf("%d ", arr[i]);
    }

    putchar('\n');
    return 0;
}

void map(int* array, size_t n, int (*func)(int))
{
    for(size_t i = 0; i < n; i++)
    {
        array[i] = func(array[i]);
    }
}

int divideNum(int num)
{
    return num / 2;
}