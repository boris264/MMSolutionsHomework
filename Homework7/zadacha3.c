#include <stdio.h>

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int));
int sum(int* arr, int size);


int main(void)
{
    int arr[] = {1, 2, 3};
    arrayEvaluate(arr, 3, sum);

    return 0;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int))
{
    int result = f(arr, n);

    printf("Value: %d\n", result);
}

int sum(int* arr, int size)
{
    int sum = 0;

    for(int i = 0;i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}