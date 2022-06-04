#include <stdio.h>
#include <limits.h>

// Compile the program with gcc zadacha1.c -o zadacha1
// Run the program with ./zadacha1 < numbers.txt

int main()
{
    int number, maxNumber = INT_MIN;

    while(scanf("%d", &number) != EOF)
    {
        if(number > maxNumber)
        {
            maxNumber = number;
        }
    }

    printf("The largest number is: %d\n", maxNumber);
    return 0;
}