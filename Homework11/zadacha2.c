#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double randReal(double min, double max);
void initializeArray(double* arr, double (*generator)(double min, double max), 
int startIndex, int size, double min, double max);
void printArray(double* arr, int size);

int main(void)
{
    srand(time(NULL));
    int n,m,p;
    double* arr;

    printf("Enter n: ");
    scanf("%d", &n);

    arr = malloc(sizeof(double) * n);
    initializeArray(arr, randReal, 0, n, 0.0, 1.0);

    printf("Enter m: ");
    scanf("%d", &m);

    arr = realloc(arr, sizeof(double) * (m + n));
    initializeArray(arr, randReal, n, m + n, 1.0, 2.0);

    printf("Enter p: ");
    scanf("%d", &p);

    arr = realloc(arr, sizeof(double) * (p + m + n));
    initializeArray(arr, randReal, m + n, p + m + n, 2.0, 3.0);

    printArray(arr, n + m + p);

    free(arr);
    
    return 0;
}

void initializeArray(double* arr, double (*generator)(double min, double max), 
    int startIndex, int size, double min, double max)
{
    for(int i = startIndex; i < size; i++)
    {
        double number = generator(min, max);
        arr[i] = number;
    }
}

void printArray(double* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%lf ", arr[i]);
    }

    putchar('\n');
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}