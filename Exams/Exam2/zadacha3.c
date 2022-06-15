#include <stdio.h>
#define COUNT 500

int main(void)
{
    char number[COUNT + 1];
    char encodedStr[COUNT + 1];

    fgets(number, COUNT, stdin);

    for(int i = 0; number[i] != '\0'; i++)
    {
        if(number[i] == '\n')
        {
            continue;
        }

        if(!(number[i] >= '0' && number[i] <= '9'))
        {
            fprintf(stderr, "Invalid number entered!\n");
            return 1;
        }

        if(i % 2 == 0)
        {
            encodedStr[i] = 'A' + (number[i] - '0');
        }
        else
        {
            switch (number[i])
            {
                case '0':
                    encodedStr[i] = '!';
                    break;
                case '1':
                    encodedStr[i] = '#';
                    break;
                case '2':
                    encodedStr[i] = '/';
                    break;
                case '3':
                    encodedStr[i] = '~';
                    break;
                case '4':
                    encodedStr[i] = '=';
                    break;
                case '5':
                    encodedStr[i] = '`';
                    break;
                case '6':
                    encodedStr[i] = '\\';
                    break;
                case '7':
                    encodedStr[i] = '>';
                    break;
                case '8':
                    encodedStr[i] = '.';
                    break;
                case '9':
                    encodedStr[i] = ',';
                    break;
            }
        }
    }

    encodedStr[COUNT] = '\0';

    printf("%s\n", encodedStr);
    return 0;
}