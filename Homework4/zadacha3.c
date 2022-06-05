#include <stdio.h>
#include <math.h>

int convert(int number, int inputBase, int outputBase);
int convertToBase10(int number, int inputBase);
int reverseNum(int n);

int main()
{
    int number, inputBase, outputBase;

    printf("Enter a number: ");
    scanf("%d", &number);

    if(number < 0)
    {
        fprintf(stderr, "Invalid number!\n");
        return 1;
    }

    printf("Enter an input base: ");
    scanf("%d", &inputBase);

    if(inputBase < 2 || inputBase > 36)
    {
        fprintf(stderr, "Invalid input base!\n");
        return 1;
    }

    printf("Enter an output base: ");
    scanf("%d", &outputBase);

    if(outputBase < 2 || outputBase > 36)
    {
        fprintf(stderr, "Invalid output base!\n");
        return 1;
    }

    printf("The number %d(%d) = %d(%d)\n", number, inputBase,convert(number, inputBase, outputBase) ,outputBase);
    return 0;
}

int convert(int number, int inputBase, int outputBase)
{
    int result = 0;
    int numberInBase10;

    if(inputBase == 10)
    {
        numberInBase10 = number;
    }
    else
    {
        numberInBase10 = convertToBase10(number, inputBase);
    }

    if(outputBase == 10)
    {
        result = convertToBase10(number, inputBase);
        return result;
    }

    int index = 0;

    while(numberInBase10 != 0)
    {
        int digit = numberInBase10 % outputBase;
        numberInBase10 /= outputBase;

        if(index == 0)
        {
            result += digit;
        }
        else
        {
            result *= 10;
            result += digit;
        }

        index++;
    }

    return reverseNum(result);
}

int convertToBase10(int number, int inputBase)
{
    int index = 0, result = 0;

    while(number != 0)
    {
        int digit = number % 10;
        number /= 10;

        result += (digit * pow(inputBase, index));
        index++;
    }

    return result;
}

int reverseNum(int n)
{
    int reverse = 0, remainder;

    while (n != 0) 
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    return reverse;
}