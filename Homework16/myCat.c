#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc == 1)
	{
		int c;

		while((c = fgetc(stdin)) != EOF)
		{
			write(STDOUT_FILENO, &c, 1);
		}

		return EXIT_SUCCESS;
	}

	for(int i = 1; i < argc; i++)
	{
		FILE* file = fopen(argv[i], "r");

		int c;

		while((c = fgetc(file)) != EOF)
		{
			write(STDOUT_FILENO, &c, 1);
		}

		fclose(file);
	}

	return 0;
}