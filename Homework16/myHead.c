#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#define DEFAULT_LINE_COUNT 10
#define DEFAULT_LINE_LENGTH 100

int main(int argc, char** argv)
{
	if(argc == 1)
	{
		fprintf(stderr, "Invalid arguments!\n");
		return EXIT_FAILURE;
	}

	for(int i = 1; i < argc; i++)
	{
		FILE* file = fopen(argv[i], "r");
		char buffer[DEFAULT_LINE_LENGTH];

		for(int a = 0; a < DEFAULT_LINE_COUNT; a++)
		{
			memset(buffer, 0, DEFAULT_LINE_LENGTH);
			fgets(buffer, DEFAULT_LINE_LENGTH, file);

			fwrite(buffer, sizeof(char), DEFAULT_LINE_LENGTH, stdout);
		}

		fclose(file);
	}

	return 0;
}
