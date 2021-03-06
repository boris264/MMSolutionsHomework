#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		fprintf(stderr, "Invalid number of arguments!\n");
		return EXIT_FAILURE;
	}

	FILE* sourceFile = fopen(argv[1], "rb");

	if(sourceFile == NULL)
	{
		perror("source file: ");
		return EXIT_FAILURE;
	}
	
	int copyPathLength = strlen(argv[2]);
	int fileNameLength = strlen(argv[1]);

	char path[copyPathLength + fileNameLength];

	strncpy(path, argv[2], copyPathLength + 1);
	strncat(path, argv[1], fileNameLength + 1);

	FILE* destinationFile = fopen(path, "wb");

	if(destinationFile == NULL)
	{
		perror("destination file: ");
		return EXIT_FAILURE;
	}

	int c;

	while((c = fgetc(sourceFile)) != EOF)
	{
		write(fileno(destinationFile), &c, 1);
	}

	fclose(sourceFile);
	fclose(destinationFile);

	return 0;
}
