#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sortNumbers(const void* num1, const void* num2)
{
    int n1 = *(int*)num1;
    int n2 = *(int*)num2;

    return n1 - n2;
}

void* routine(void* arg)
{
    long* arguments = (long*)arg;
    
    qsort((long*)arguments[0], arguments[1], sizeof(int), sortNumbers);

    return (long*)arguments[0];   
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    pthread_t threads[n];

    int threadIndex = 0;

    for(int i = 0; i < n; i++)
    {
        char row[4];
        int rowNum;

        scanf("%s", row);
        scanf(" %d", &rowNum);
        
        int* numbers = malloc(sizeof(int) * m);

        for(int a = 0; a < m; a++)
        {
            scanf("%d ", numbers + a);
        }

        long threadArgs[2] = {(long)numbers, m};

        pthread_t threadId;
        pthread_create(&threadId, NULL, routine, (void*)threadArgs);

        threads[threadIndex++] = threadId;
    }

    char fileName[31];
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "w");

    if(file == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < threadIndex; i++)
    {
        void* retValue;
        pthread_join(threads[i], &retValue);

        fprintf(file, "ROW %d ", i + 1);
        
        for(int a = 0; a < m; a++)
        {
            fprintf(file, "%d ", ((int*)retValue)[a]);
        }

        fprintf(file, "\n");

        free(retValue);
    }

    fclose(file);

    return 0;
}