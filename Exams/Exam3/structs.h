#ifndef _STRUCTS
#define _STRUCTS

typedef struct point{
    double x;
    double y;

} point_t;

typedef struct rectangle{
    point_t A;
    point_t B;

} rectangle_t;

typedef struct node {
    rectangle_t rectangle;
    struct node* next;
} node_t;
#endif