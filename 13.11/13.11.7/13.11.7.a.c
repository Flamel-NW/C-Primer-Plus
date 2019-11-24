//¡¶C Primer Plus¡·p437 13.11.7.a
#include <stdio.h>
#include <stdlib.h>
#define SIZE 512

int main(int argc, char * argv [])
{
	FILE * file1, * file2;
	char temp[SIZE];
	
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((file1 = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((file2 = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		if (fgets(temp, SIZE, file1) != NULL)
		{
			fputs(temp, stdout);
		}
		else
		{
			while (fgets(temp, SIZE, file2) != NULL)
			{
				fputs(temp, stdout);
			}
			break;
		}
		
		if (fgets(temp, SIZE, file2) != NULL)
		{
			fputs(temp, stdout);
		}
		else
		{
			while (fgets(temp, SIZE, file1) != NULL)
			{
				fputs(temp, stdout);
			}
			break;
		}
	}
	
	if (fclose(file1) == EOF)
	{
		fprintf(stderr, "Error in closing file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fclose(file2) == EOF)
	{
		fprintf(stderr, "Error in closing file %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	printf("Done.\n");
	
	return 0;
}
