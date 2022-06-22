#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_SIZE 100

typedef struct queue{
	int array[MAX_SIZE];
	unsigned count;
	int top;

} queue_t;

queue_t* CreateQueue();
void DeleteQueue(queue_t* queue);
int IsEmpty(queue_t* queue);
int IsFull(queue_t* queue);
void Push(queue_t* queue, int newElement);
int Pop(queue_t* queue);

int main(void)
{
	queue_t* queue = CreateQueue();
	printf("%d\n", IsEmpty(queue));
	printf("%d\n", IsFull(queue));
	Push(queue, 65);
	Push(queue, 6532);
	Push(queue, 998);
	Push(queue, 99845);
	printf("%d\n", Pop(queue));
	printf("%d\n", Pop(queue));
	printf("%d\n", Pop(queue));
	printf("%d\n", Pop(queue));

	DeleteQueue(queue);
	return 0;
}

queue_t* CreateQueue()
{
	queue_t* queue = malloc(sizeof(queue_t));
	memset(queue->array, 0, MAX_SIZE);
	queue->count = 0;
	queue->top = 0;

	return queue;
}

void DeleteQueue(queue_t* queue)
{
	free(queue);
}

int IsEmpty(queue_t* queue)
{
	return queue->count == 0 ? 0 : 1;
}

int IsFull(queue_t* queue)
{
	return queue->count == MAX_SIZE ? 0 : 1;
}

void Push(queue_t* queue, int newElement)
{
	queue->array[queue->count] = newElement;
	queue->count++;
}

int Pop(queue_t* queue)
{
	return queue->array[queue->top++];
}
