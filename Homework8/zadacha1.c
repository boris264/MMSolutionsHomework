#include <stdio.h>

int mystrncmp(const char* str1, const char* str2, size_t n);

int main(void)
{
    printf("%d\n", mystrncmp("abcde", "abcdd", 5));
    return 0;
}

int mystrncmp(const char* str1, const char* str2, size_t n)
{
    int result = 0;

    unsigned str1NumericValue = 0;
    unsigned str2NumericValue = 0;

    for(size_t i = 0; i < n; i++)
    {
        if(str1[i] != str2[i])
        {
            str1NumericValue += str1[i];
            str2NumericValue += str2[i];
        }
    }

    result = str1NumericValue - str2NumericValue;

    return result;
}