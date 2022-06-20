#include "llist.h"

void push(node_t** list, rectangle_t rectangle){
    node_t* n = malloc(sizeof(node_t));
    n->rectangle = rectangle;
    n->next = *list;
    *list = n;
}

void print_list(node_t* list)
{
    if(list == NULL)
    {
        return;
    }

    node_t* current = list;

    while (current){
        printf("A: x=%lf, y=%lf | B: x=%lf, y=%lf\n", current->rectangle.A.x, current->rectangle.A.y, 
            current->rectangle.B.x, current->rectangle.B.y);
        current = current->next;
    }
    putchar('\n');
}

void deleteNth(node_t** list, size_t n)
{
    if (*list == NULL){
        return;
    }

    if (n == 0){
        node_t* temp = *list;
        *list = (*list)->next;
        free(temp);
        return;
    }

    node_t* current = *list;
    node_t* prev = current;

    while (current && n--) 
    {
        prev = current;
        current = current->next;
    }
    
    prev->next = current->next;
    free(current);
}