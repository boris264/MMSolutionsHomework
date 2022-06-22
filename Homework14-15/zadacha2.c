#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 15

typedef struct {
	char title[150];
	char author[100];
	unsigned short pages;
	double price;

} Book;

typedef struct node {
    Book data;
    struct node* next;
} node_t;


void push(node_t** head, Book value);
void printElements(node_t* head);
int sortByTitle(const void* book1, const void* book2);

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "Not enough arguments!\n");
		return EXIT_FAILURE;
	}

	node_t* head = NULL;

	FILE* f = fopen(argv[1], "rb");
	Book books[COUNT];

	fread(books, sizeof(Book), COUNT, f);

	fclose(f);

	qsort(books, COUNT, sizeof(Book), sortByTitle);

	for(int i = 0; i < COUNT; i++)
	{
		push(&head, books[i]);
	}

	printElements(head);

	FILE* output = fopen(argv[2], "wb");

	fwrite(books, sizeof(Book), COUNT, output);

	fclose(output);

	return 0;
}

int sortByTitle(const void* book1, const void* book2)
{
	Book* b1 = (Book*)book1;
	Book* b2 = (Book*)book2;

	return strcmp(b1->title, b2->title);
}

void push(node_t** head, Book value)
{
    node_t* temp = malloc(sizeof(node_t));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void printElements(node_t* head)
{
    node_t* current = head;

    while (current != NULL)
	{
        printf("Title: %s, Author: %s, Pages: %d, Price: %lf\n", current->data.title, current->data.author, current->data.pages, current->data.price);
        current = current->next;
    }
	
    putchar('\n');
}
