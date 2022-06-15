#ifndef _CAR_
#define _CAR_

#include <stdint.h>

struct Car{
    char model[20];
    uint16_t maxspeed;
    double price;

};
int sortByModelASC(const void *, const void*);
int sortByModelDESC(const void *, const void*);
int sortBySpeedASC(const void *, const void*);
int sortBySpeedDESC(const void *, const void*);
int sortByPriceASC(const void *, const void*);
int sortByPriceDESC(const void *, const void*);
int (*getComparator(int n))(const void*, const void*);

#endif