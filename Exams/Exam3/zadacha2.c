#include <stdio.h>
#include <string.h>
#include <stdint.h>

void binToText(FILE* src, FILE* dst);
void textToBin(FILE* src, FILE* dst);

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        fprintf(stderr, "Insufficient number of arguments!\n");
        return 1;
    }

    char* sourceFile = argv[1];
    char* destFile = argv[2];
    char* mode = argv[3];

    if(!strcmp(mode, "-BT"))
    {
        FILE* source = fopen(sourceFile, "rb");
        FILE* dest = fopen(destFile, "w");

        binToText(source, dest);
    }
    else if(!strcmp(mode, "-TB"))
    {
        FILE* source = fopen(sourceFile, "r");
        FILE* dest = fopen(destFile, "wb");

        textToBin(source, dest);
    }
    else
    {
        fprintf(stderr, "Invalid mode!\n");
        return 1;
    }

    return 0;
}

void binToText(FILE* src, FILE* dst)
{
    if(src == NULL || dst == NULL)
    {
        fprintf(stderr, "Error opening files!\n");
        return;
    }

    char c;

    while((c = fgetc(src)) != EOF)
    {
        fprintf(dst, "%d\n", c);
    }
}

void textToBin(FILE* src, FILE* dst)
{
    if(src == NULL || dst == NULL)
    {
        fprintf(stderr, "Error opening files!\n");
        return;
    }

    int16_t c;

    while(fread(&c, sizeof(int16_t), 1, src) != 0)
    {         
        fwrite(&c, sizeof(int16_t), 1, dst);
    }
}