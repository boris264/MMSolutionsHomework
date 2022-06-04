#include <stdio.h>
#include <math.h>

// Compile the program with gcc zadacha1.c -lm -o zadacha1

int main()
{
    int option;
    double kilograms = 0, meters = 0, bmi;

    printf("How to calculate the body mass index?\n 1) Old formula\n 2) New formula\n");
    scanf("%d", &option);

    if(option != 1 && option != 2)
    {
        fprintf(stderr, "Invalid option selected!\n");
        return 1;
    }

    printf("Enter kilograms: ");
    scanf("%lf", &kilograms);

    printf("Enter meters: ");
    scanf("%lf", &meters);

    if(kilograms <= 0 || meters <= 0)
    {
        fprintf(stderr, "Invalid values provided for either mass or height!\n");
        return 1;
    }

    if(option == 1)
    {
        bmi = kilograms / (pow(meters, 2));
    }
    else if( option == 2)
    {
        bmi = 1.3 * (kilograms / (pow(meters, 2.5)));
    }

    printf("The BMI is: %.1lf\n", bmi);
    return 0;
}