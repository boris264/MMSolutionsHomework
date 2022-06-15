#include <stdio.h>
#include <string.h>
#include "car.h"

int sortByModelASC(const void * car1, const void* car2)
{
    struct Car* c1 = (struct Car*)car1;
    struct Car* c2 = (struct Car*)car2;

    return strcmp(c1->model, c2->model);
}

int sortByModelDESC(const void* car1, const void* car2)
{
    struct Car* c1 = (struct Car*)car1;
    struct Car* c2 = (struct Car*)car2;

    return strcmp(c2->model, c1->model);
}

int sortBySpeedASC(const void* car1, const void* car2)
{
    struct Car* c1 = (struct Car*)car1;
    struct Car* c2 = (struct Car*)car2;

    return c1->maxspeed - c2->maxspeed;
}

int sortBySpeedDESC(const void* car1, const void* car2)
{
    struct Car* c1 = (struct Car*)car1;
    struct Car* c2 = (struct Car*)car2;

    return c2->maxspeed - c1->maxspeed;
}

int sortByPriceASC(const void* car1, const void* car2)
{
    struct Car* c1 = (struct Car*)car1;
    struct Car* c2 = (struct Car*)car2;

    if(c1->price - c2->price < 0.001)
    {
        return 0;
    }
    else
    {
        return 1;
    }

    return -1;
}

int sortByPriceDESC(const void* car1, const void* car2)
{
    struct Car* c1 = (struct Car*)car1;
    struct Car* c2 = (struct Car*)car2;

    if(c2->price - c1->price < 0.001)
    {
        return 0;
    }
    else
    {
        return 1;
    }

    return -1;
}

int (*getComparator(int n))(const void*, const void*)
{
    int (*comp[])(const void*, const void*) = 
    {
        sortByModelASC,
        sortByModelDESC,
        sortBySpeedASC,
        sortBySpeedDESC,
        sortByPriceASC,
        sortByPriceDESC
    };

    if(n >= 1 && n <= 6)
    {
        return comp[n - 1];
    }

    fprintf(stderr, "Function with index %d not found!\n", n);
    
    return NULL;
}