#include <stdio.h>
#include <limits.h>

int secondMax(const int* arr, size_t n, int* secondMax);

int main(void)
{
    int sm = 0;
    int arr[] = {12, 34, 5, 70, 46 };

    secondMax(arr, 2, &sm);

    printf("%d\n", sm);
    return 0;
}

int secondMax(const int* arr, size_t n, int* secondMax)
{
    if(n == 0)
    {
        fprintf(stderr, "Array is empty!\n");
        return -1;
    }
    else if (n == 1)
    {
        fprintf(stderr, "Array has only 1 element!\n");
        return -1;
    }

    int max = arr[0], areEqual = 1;

    for(size_t i = 0; i < n; i++)
    {
        if(arr[i] != max)
        {
            areEqual = 0;
        }

        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    if(areEqual)
    {
        fprintf(stderr, "Elements in the array are the same!\n");
        return -1;
    }

    *secondMax = INT_MIN;

    for(size_t i = 0; i < n; i++)
    {
        if(arr[i] != max && arr[i] > *secondMax)
        {
            *secondMax = arr[i];
        }
    }

    return 0;
}