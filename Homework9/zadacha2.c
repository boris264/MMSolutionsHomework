#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
void *linearSearch(const void *key, void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
int bookPriceSearch(const void* price, const void* book);

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
        books[i].price = randReal(20.48, 20.51);
    }

    double bPrice = 20.50;

    void* bookPtr = linearSearch(&bPrice, books, COUNT, sizeof(books[0]), bookPriceSearch);
    
    if(bookPtr != NULL)
    {
        struct Book* book = (struct Book*)bookPtr;
        printf("Title: %s, Author: %s, Pages: %d, Price: %lf\n", book->title, book->author, book->pages, book->price);
    }
    else
    {
        fprintf(stderr, "No books with price 20.50 were found!\n");
    }

    return 0;
}

int bookPriceSearch(const void* price, const void* book)
{
    struct Book* b1 = (struct Book*)book;
    double* pr = (double*)price;

    if (fabs(b1->price - *pr) < 0.001){
        return 0;
    } else if (b1->price > *pr){
        return 1;
    }

    return -1;
}

void *linearSearch(const void *key, void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
    for (int i = 0; i < nitems; i++){
        if(compar(key, base + i * size) == 0){
            return base + i * size;
        }
    }
    return NULL;
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
    struct Book* b1 = (struct Book*)book1;
    struct Book* b2 = (struct Book*)book2;

    if (fabs(b1->price - b2->price) < 0.001){
        return 0;
    } else if (b1->price > b2->price){
        return 1;
    }
    return -1;
}

int priceSortDESC(const void* book1, const void* book2)
{
    struct Book* b1 = (struct Book*)book1;
    struct Book* b2 = (struct Book*)book2;

    if (fabs(b1->price - b2->price) < 0.001){
        return 0;
    } else if (b1->price > b2->price){
        return 1;
    }
    return -1;
}