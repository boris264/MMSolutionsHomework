#include <stdio.h>
#include <math.h>

int main()
{
    double R = 0, H = 0, L = 0, waterVolume = 0;

    printf("Enter R: ");
    scanf("%lf", &R);

    printf("Enter H: ");
    scanf("%lf", &H);

    printf("Enter L: ");
    scanf("%lf", &L);

    if(R <= 0 || H <= 0 || L <= 0)
    {
        fprintf(stderr, "Invalid value provided for either R or H or L!\n");
        return 1;
    }

    double cylinderArea = acos((R - H) / R) * pow(R, 2) - (R - H) * sqrt(2 * R * H - pow(H, 2));
    waterVolume = cylinderArea * L;

    printf("The volume of the water in the cylinder is: %.2lf\n", waterVolume);
    return 0;
}