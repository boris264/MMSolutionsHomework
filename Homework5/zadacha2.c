#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* S, double *P);

int main(void)
{
    double a, b, c;

    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF)
    {
        double S, P;
        int result = triangle(a, b, c, &S, &P);
        
        if(result == -1)
        {
            fprintf(stderr, "Invalid triangle sides!\n");
        }
        else
        {
            printf("S = %.2lf\nP = %.2lf\n", S, P);
        }
    }

    return 0;
}

int triangle(double a, double b, double c, double* S, double *P)
{
    if (a + b <= c || a + c <= b || b + c <= a)
    {
        return -1;
    }

    *P = a + b + c;
    double p = ( a + b + c) / 2;

    // Didn't know which formula to use.
    
    //*S = sqrt(p * (p - a) * (p - b) * (p - c));
    *S = (a * b) / 2;
    return 0;
}