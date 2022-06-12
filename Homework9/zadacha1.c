#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 15

void randomName(char* name);
int randInt(int min, int max);
double randReal(double min, double max);
int titleSortASC(const void* book1, const void* book2);
int titleSortDESC(const void* book1, const void* book2);
int authorSortDESC(const void* book1, const void* book2);
int authorSortASC(const void* book1, const void* book2);
int pagesSortASC(const void* book1, const void* book2);
int pagesSortDESC(const void* book1, const void* book2);
int priceSortASC(const void* book1, const void* book2);
int priceSortDESC(const void* book1, const void* book2);
//void printBook(struct Book* book);

struct Book{
    char title[151];
    char author[101];
    int pages;
    double price;
};

int main(void)
{
    srand(time(NULL));
    struct Book books[COUNT];

    for(int i = 0; i < COUNT; i++)
    {
        randomName(books[i].title); 
        randomName(books[i].author); 
        books[i].pages = randInt(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }

    for(int i = 0; i < COUNT; i++)
    {
        qsort(books, COUNT, sizeof(books[0]), titleSortDESC);
        printf("Title: %s, Author: %s, Pages: %d, Price: %lf\n", books[i].title, books[i].author, books[i].pages, books[i].price);
    }

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

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int titleSortASC(const void* book1, const void* book2)
{
    struct Book* b1 = (struct Book*)book1;
    struct Book* b2 = (struct Book*)book2;

    return strcmp(b1->title, b2->title);
}

int titleSortDESC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    return strcmp(b2.title, b1.title);
}

int authorSortASC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    return strcmp(b1.author, b2.author);
}

int authorSortDESC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    return strcmp(b2.author, b1.author);
}

int pagesSortASC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    return b1.pages - b2.pages;
}

int pagesSortDESC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    return b2.pages - b1.pages;
}

int priceSortASC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    if(b1.price - b2.price < 0.001)
    {
        return 0;
    }

    return b1.price - b2.price;
}

int priceSortDESC(const void* book1, const void* book2)
{
    struct Book b1 = *(struct Book*)book1;
    struct Book b2 = *(struct Book*)book2;

    if(b2.price - b1.price < 0.001)
    {
        return 0;
    }

    return b2.price - b1.price;
}