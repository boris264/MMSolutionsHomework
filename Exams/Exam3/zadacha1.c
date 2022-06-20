#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include <math.h>
#include "llist.h"

#define COUNT 15

double randReal(double min, double max);
rectangle_t createRectangle();
double areaRects(node_t* list);
void filterRects(node_t** list, double min, double max);
double calculateArea(rectangle_t* rect);

int main(void)
{
    srand(time(NULL));
    node_t* head = NULL;

    for(int i = 0; i < COUNT; i++)
    {
        rectangle_t rect = createRectangle();
        push(&head, rect);
    }

    print_list(head);
    printf("%lf\n", areaRects(head));
    filterRects(&head, -1000.0, 1000.0);
    print_list(head);
    return 0;
}



rectangle_t createRectangle()
{
    rectangle_t rectangle;
    point_t a;
    point_t b;
    a.x = randReal(-10.0, 10.0);
    a.y = randReal(-10.0, 10.0);
    b.x = randReal(-10.0, 10.0);
    b.y = randReal(-10.0, 10.0);
    rectangle.A = a;
    rectangle.B = b;

    return rectangle;
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

double areaRects(node_t* list)
{
    double sum = 0;
    node_t* current = list;

    while(current != NULL)
    {
        sum += calculateArea(&current->rectangle);
        current = current->next;
    }

    return sum;
}

void filterRects(node_t** list, double min, double max)
{
    node_t* current = *list;
    int i = 0;

    while(current != NULL)
    {
        double currentArea = calculateArea(&current->rectangle);

        if(currentArea >= min && currentArea <= max)
        {  
            printf("%lf\n", currentArea);
            deleteNth(list, i);
        }

        current = current->next;
        i++;
    }
}

double calculateArea(rectangle_t* rect)
{
    double area = 0;

    double currentLength = abs(rect->A.x - rect->B.x);
    double currentWidth = abs(rect->A.y - rect->B.y);

    area = currentLength * 2 + currentWidth * 2;
    return area;
}