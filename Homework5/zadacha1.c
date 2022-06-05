#include <stdio.h>

double calculate(double num1, char operation, double num2);

int main(void)
{
    double num1, num2;
    char operation;

    while(scanf("%lf %c %lf", &num1, &operation, &num2) != EOF)
    {
        double result = calculate(num1, operation, num2);
        printf("%.2lf\n", result);
    }

    return 0;
}

double calculate(double num1, char operation, double num2)
{
    double result = 0;

    switch(operation)
    {
        case '+':
            result =  num1 + num2;

            break;
        case '-':
            result =  num1 - num2;

            break;
        case '*':
            result =  num1 * num2;

            break;
        case '/':
            result =  num1 / num2;

            break;
        default:
            fprintf(stderr, "Invalid operation selected!\n");
            return -1;
    }

    return result;
}