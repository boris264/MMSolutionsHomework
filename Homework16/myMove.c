#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "strings.h"

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
		perror("Source: ");
		return EXIT_FAILURE;
	}
	
	char* sourceFileName = strrchr(argv[1], '/') + 1;

	char destinationPath[strlen(argv[2]) + strlen(sourceFileName) + 1];

	strncpy(destinationPath, argv[2], strlen(argv[2]) + 1);
	strncat(destinationPath, sourceFileName, strlen(sourceFileName));

	FILE* destinationFile = fopen(destinationPath, "wb");

	if(destinationFile == NULL)
	{
		perror("Destination: ");
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
