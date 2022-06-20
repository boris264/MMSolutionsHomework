#ifndef _LLIST_H
#define _LLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void push(node_t** list, rectangle_t rectangle);
void print_list(node_t* list);
void deleteNth(node_t** list, size_t n);

#endif