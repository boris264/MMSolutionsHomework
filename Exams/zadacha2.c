#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define BUFFER_SIZE 10


int main(int argc, char** argv)
{
    if(argc == 1)
    {
        fprintf(stderr, "Not enough arguments!\n");
        return EXIT_FAILURE;
    }

    int fd[2];
    int totalSum = 0;
    pipe(fd);

    for(int i = 1; i < argc; i++)
    {
        FILE* file = fopen(argv[i], "r");

        if(file == NULL)
        {
            perror(argv[i]);
            continue;
        }

        pid_t pid = fork();

        if(-1 == pid)
        {
            perror("fork");
            return EXIT_FAILURE;
        }
        else if(0 == pid)
        {
            int sum = 0;
            char input[BUFFER_SIZE + 1];
            
            while(fgets(input, BUFFER_SIZE + 1, file) != NULL)
            {
                int number = atoi(input);
                sum += number;

                memset(input, 0, BUFFER_SIZE + 1);
            }

            write(fd[1], &sum, sizeof(int));

            printf("File%d: %d\n", i, sum);
            
            fclose(file);

            exit(0);
        }
        else
        {
            int statusCode;
            wait(&statusCode);

            if(WEXITSTATUS(statusCode) == 0)
            {
                int fileSum = 0;

                read(fd[0], &fileSum, sizeof(int));
                totalSum += fileSum;
            }
        }
    }

    printf("Total sum: %d\n", totalSum);

    return 0;
}