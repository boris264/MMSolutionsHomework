#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int quadEq(double a, double b, double c);

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        fprintf(stderr, "Too few arguments!\n");
        return -1;
    }
    
    double a = strtod(argv[1], NULL);
    double b = strtod(argv[2], NULL);
    double c = strtod(argv[3], NULL);

    int result = quadEq(a, b, c);

    return 0;
}

int quadEq(double a, double b, double c)
{
    if(a <= 0)
    {
        return -1;
    }

    int D = pow(b, 2) - 4 * 1 * c;

    if(D < 0)
    {
        printf("No real roots\n");
    }
    else if(D == 0)
    {
        double x = -(b / (2 * a));
        printf("x = %.2lf\n", x);
    }
    else
    {
        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);

        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }

    return 0;
}