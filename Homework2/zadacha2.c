#include <stdio.h>

// Run the program with ./zadacha2 < numbers2.txt

int main()
{
    int number1, number2, number3;

    scanf("%d", &number1);
    scanf("%d", &number2);
    scanf("%d", &number3);

    int result = number1 ^ number2 ^ number3;

    if(result)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}