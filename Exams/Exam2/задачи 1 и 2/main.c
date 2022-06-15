#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "car.h"

#define COUNT 10

int randint(int,int);
double randReal(double,double);
char* randomName(char*);

int main(void)
{
    srand(time(NULL));
    int funcIndex;
    printf("Enter an option to sort the array: \n1)By model ascending\n2)By model descending\n3)By speed ascending\n4)By speed descending\n5)By price ascending\n6)By price descending\n");
    scanf("%d", &funcIndex);

    struct Car cars[COUNT];

    for(int i = 0; i < COUNT; i++)
    {
        randomName(cars[i].model);
        cars[i].maxspeed = randint(100, 300);
        cars[i].price = randReal(1000.0, 100000.0);
    }
    
    qsort(cars, COUNT, sizeof(cars[0]), getComparator(funcIndex));

    for(int i = 0; i < COUNT; i++)
    {
        printf("Model: %s\nMax speed: %d\nPrice: %lf\n", cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    return 0;
}


int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char* randomName(char* name){
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(4, 10);

    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }

    // name[index++] = ' ';
    // n = randint(5, 10);
    // name[index++] = randint('A', 'Z');

    // for (int i = 0; i < n; i++){
    //     name[index++] = randint('a', 'z');
    // }

    name[index] = '\0';
    return name;
}