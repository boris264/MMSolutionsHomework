#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 15

double randReal(double min, double max);
void randomName(char* name);
int randInt(int min, int max);

typedef struct {
	char title[150];
	char author[100];
	unsigned short pages;
	double price;

} Book;

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "Not enough arguments!\n");
		return EXIT_FAILURE;
	}

    srand(time(NULL));
    Book books[COUNT];

    for(int i = 0; i < COUNT; i++)
    {
        randomName(books[i].title); 
        randomName(books[i].author); 
        books[i].pages = randInt(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }

	FILE* f = fopen(argv[1], "wb");

	fwrite(books, COUNT, sizeof(books[0]), f);

	fclose(f);

    return 0;
}


void randomName(char* name)
{
    name[0] = randInt('A', 'Z');
    int i;
    int randomCount = randInt(5, 10);

    for(i = 1; i <= randomCount; i++)
    {
        name[i] = randInt('a', 'z');
    }

    name[i++] = ' ';
    name[i++] = randInt('A', 'Z');
    
    randomCount = randInt(5, 10) + i;
    
    for(;i < randomCount; i++)
    {
        name[i] = randInt('a', 'z');
    }

    name[i] = 0;
}

int randInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}