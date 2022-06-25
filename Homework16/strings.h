#ifndef __STRINGS__
#define __STRINGS__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char** tokenizeString(const char* str, const char delimiter, int* returnedArraySize);
void freeTokenizedString(char** arr, int size);

#endif