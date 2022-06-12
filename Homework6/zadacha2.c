#include <stdio.h>
#include <math.h>

double factorial(double num);
double customSin(double num);

int main(void)
{
    printf("%lf\n", customSin(2));
    return 0;
}

double factorial(double num)
{
    double result = 1;

    for(int i = 1; i <= num; i++)
    {
        result *= i;
    }

    return result;
}

double customSin(double num)
{
    double result = 1 + num;

    for(int i = 0; i < 9; i++)
    {
        result += pow(num, i + 2) / factorial(i + 2);
    }

    return result;
}