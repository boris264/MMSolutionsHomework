#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <float.h>
#include <time.h>

#define ITEMS_COUNT 10

typedef struct Item{
    uint16_t id;
    char description[251];
    double weight;
    double price;

} Item;

typedef struct node {
    struct Item item;
    struct node* next;
} node_t;


void printList(node_t* head);
void push(node_t** head, struct Item value);
double totalItemsWeight(node_t* items);
node_t *minPriceItem(node_t* items);
int randint(int min, int max);
char* randomName(char* name);
double randReal(double min, double max);

int main(void)
{
    srand(time(NULL));
    node_t* head = NULL;

    for(int i = 0; i < ITEMS_COUNT; i++)
    {
        Item item;
        memset(item.description, 0, 250);
        item.id = randint(0, UINT16_MAX);
        int n = randint(5, 10);

        for(int a = 0; a < n; a++)
        {
            char word[12];
            randomName(word);
            strncat(item.description, word, strlen(word));
        }

        item.weight = randReal(0.100, 100.0);
        item.price = randReal(1.0, 1500.0);

        push(&head, item);
    }

    printList(head);
    node_t* el = minPriceItem(head);

    printf("Total weight: %lf\n", totalItemsWeight(head));
    printf("Cheapest item: %lf\n", el->item.price);
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
    int n = randint(1, 10);

    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }

    name[index++] = ' ';
    name[index] = '\0';
    return name;
}

void push(node_t** head, struct Item value){
    node_t* temp = malloc(sizeof(node_t));
    temp->item = value;
    temp->next = *head;
    *head = temp;

}

void printList(node_t* head)
{
    node_t* current = head;

    while(current != NULL)
    {
        
        printf("ID: %d, Description: %s, Weight: %lf, Price: %lf\n", current->item.id,
            current->item.description, current->item.weight, current->item.price);
        current = current->next;
    }
}

double totalItemsWeight(node_t* items)
{
    node_t* current = items;
    double sum = -1;

    while(current != NULL)
    {
        sum += current->item.weight; 
        current = current->next;
    }

    return sum;
}

node_t *minPriceItem(node_t* items)
{
    node_t* elementWithLowestPrice = NULL;
    node_t* current = items;
    double min = DBL_MAX;

    while(current != NULL)
    {
        if(current->item.price - min < 0.001)
        {
            min = current->item.price;
            elementWithLowestPrice = current;
        }

        current = current->next;
    }

    return elementWithLowestPrice;
}