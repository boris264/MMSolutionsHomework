#include <stdio.h>
#include <stdint.h>
#define TINT 0
#define TCHAR 1
#define TFLOAT 2
#define TDOUBLE 3
#define UINT8_T 4
#define UINT16_T 5
#define UINT32_T 6
#define UINT64_T 7

void printValue(const void* valuePtr, uint8_t flag);

int main(void)
{
    int a;
    scanf("%d", &a);
    printValue(&a, 1);
    return 0;
}

void printValue(const void* valuePtr, uint8_t flag)
{
    switch (flag)
    {
    case TINT:
        printf("%d\n", *(int*)valuePtr);
        break;
    case TCHAR:
        printf("%c\n", *(char*)valuePtr);
        break;
    case TFLOAT:
        printf("%f\n", *(float*)valuePtr);
        break;
    case TDOUBLE:
        printf("%lf\n", *(double*)valuePtr);
        break;
    case UINT8_T:
        printf("%u\n", *(uint8_t*)valuePtr);
        break;
    case UINT16_T:
        printf("%u\n", *(uint16_t*)valuePtr);
        break;
    case UINT32_T:
        printf("%u\n", *(uint32_t*)valuePtr);
        break;
    case UINT64_T:
        printf("%ld\n", *(uint64_t*)valuePtr);
        break;

    default:
        fprintf(stderr, "Invalid flag!\n");
        break;
    }
}