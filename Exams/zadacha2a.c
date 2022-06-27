#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 10

void* routine(void* arg)
{
    int* sum = malloc(sizeof(int));
    FILE* file = (FILE*)arg;

    char input[BUFFER_SIZE + 1];
            
    while(fgets(input, BUFFER_SIZE + 1, file) != NULL)
    {
        int number = atoi(input);
        *sum += number;

        memset(input, 0, BUFFER_SIZE + 1);
    }

    printf("File: %d\n", *sum);

    return sum;
}

int totalSum = 0;

int main(int argc, char** argv)
{
    pthread_t threads[argc - 1];
    int threadIndex = 0;

    if(argc == 1)
    {
        fprintf(stderr, "Not enough arguments!\n");
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc; i++)
    {
        FILE* file = fopen(argv[i], "r");

        if(file == NULL)
        {
            perror(argv[i]);
            continue;
        }

        pthread_t threadId;
        pthread_create(&threadId, NULL, routine, (void*)file);

        threads[threadIndex++] = threadId;
    }

    for(int i = 0; i < threadIndex; i++)
    {
        void* retValue;
        pthread_join(threads[i], &retValue);
        totalSum += *(int*)retValue;

        free(retValue);
    }

    printf("Total sum: %d\n", totalSum);

    return 0;
}