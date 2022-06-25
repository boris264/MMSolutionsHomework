#include "strings.h"
#define INITIAL_ARR_SIZE 10 

char** tokenizeString(const char* str, const char delimiter, int* returnedArraySize)
{
    int length = strlen(str);
    char** initialArray = malloc(sizeof(char*) * INITIAL_ARR_SIZE);
    char strContainer[length];

    memset(strContainer, 0, length);

    int initialArrIndex = 0;
    int strContainerIndex = 0;
    int strContainerLength = 0;

    for (int i = 0; i < length; i++)
    {
        if(str[i] == delimiter)
        {
            strContainerLength = strlen(strContainer);
            
            initialArray[initialArrIndex] = malloc(sizeof(char) * strContainerLength);
            strncpy(initialArray[initialArrIndex], strContainer, strContainerLength);
            memset(strContainer, 0, length);

            strContainerIndex = 0;
            initialArrIndex++;

            continue;
        }

        strContainer[strContainerIndex] = str[i];
        strContainerIndex++;
    }

    strContainerLength = strlen(strContainer);       
    initialArray[initialArrIndex] = malloc(sizeof(char) * strContainerLength);
    strncpy(initialArray[initialArrIndex], strContainer, strContainerLength);

    *returnedArraySize = initialArrIndex + 1;

    return initialArray;
}
