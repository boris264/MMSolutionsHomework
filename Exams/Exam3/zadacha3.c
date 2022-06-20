#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void push(Node** list, int data);
void print_list(Node* list);

int main()
{
    Node* list = NULL;
   
    push(&list, 135);
    print_list(list);
    // int n;
    // scanf("%d", &n);

    // for(int i = 0; i < n; i++)
    // {
    //     int currentNum;
    //     scanf("%d", &currentNum);


    // }

    return 0;
}

void push(Node** list, int data)
{
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = *list;

    if(*list != NULL)
    {
        (*list)->next = temp;
    }

    *list = temp;
}

void print_list(Node* list)
{
    Node* current = list;

    do
    {
        printf("%d\n", current->data);
        current = current->next;

    } while (current != list);
    
}