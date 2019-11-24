//¡¶C Primer Plus¡·p437 13.11.11
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 256

int main(int argc, char * argv [])
{
	FILE * fp;
	char row[LENGTH];
	
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(row, LENGTH, fp) != NULL)
	{
		if (strstr(row, argv[1]) != NULL)
		{
			fputs(row, stdout);
		}
	}
	
	if (fclose(fp) == EOF)
	{
		fprintf(stderr, "Error in closing file %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("Done.\n");
	
	return 0;
}
