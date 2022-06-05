#include <stdio.h>

int rectangle(double w, double h, double* S, double *P);

int main(void)
{
    double w, h;

    while(scanf("%lf %lf", &w, &h) != EOF)
    {
        double S, P;
        int result = rectangle(w, h, &S, &P);
        
        if(result == -1)
        {
            fprintf(stderr, "Invalid rectangle sides!\n");
        }
        else
        {
            printf("S = %.2lf\nP = %.2lf\n", S, P);
        }
    }

    return 0;
}

int rectangle(double w, double h, double* S, double *P)
{
    if(w <= 0 || h <= 0)
    {
        return -1;
    }

    *P = (w + h) * 2;
    *S = w * h;

    return 0;
}