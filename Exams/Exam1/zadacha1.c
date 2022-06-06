#include <stdio.h>
#include <math.h>

int cylinder(double r, double h, double* V, double* S);

int main(void)
{
    double r, h;

    while(scanf("%lf %lf", &r, &h) != EOF)
    {
        double V, S;
        int result = cylinder(r, h, &V, &S);

        if(result == -1)
        {
            fprintf(stderr, "Invalid data\n");
        }
        else
        {
            printf("V = %.2lf, S = %.2lf\n", V, S);
        }
    }

    return 0;
}

int cylinder(double r, double h, double* V, double* S)
{
    if(r <= 0 || h <= 0)
    {
        return -1;
    }

    *V = M_PI * pow(r, 2) * h;
    *S = 2 * M_PI * r * (r + h);

    return 0;
}