#include <stdio.h>
#include <math.h>

int main()
{
    double R = 0, H = 0, waterVolume = 0;

    printf("Enter R: ");
    scanf("%lf", &R);

    printf("Enter H: ");
    scanf("%lf", &H);

    if(R <= 0 || H <= 0)
    {
        fprintf(stderr, "Invalid value provided for either R or H!\n");
        return 1;
    }

    waterVolume = M_PI * (pow(R, 2)) * H;

    printf("The water volume is: %.2lf\n", waterVolume);
    return 0;
}