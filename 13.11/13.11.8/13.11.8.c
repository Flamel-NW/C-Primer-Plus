//¡¶C Primer Plus¡·p437 13.11.8
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv [])
{
	FILE * search_in;
	int temp;
	char target;
	int num = 0;
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	target = argv[1][0];
	
	if (argc == 2)
	{
		while ((temp = getc(stdin)) != EOF)
		{
			num += ((char) temp == target) ? 1 : 0;
		}
		printf("There are %d '%c's in stdin.\n", num, target);
	}
	else
	{
		int i;
		for (i = 2; i < argc; i++)
		{
			num = 0;
			if ((search_in = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open %s.\n", argv[i]);
				continue;
			}
			while ((temp = getc(search_in)) != EOF)
			{
				num += ((char) temp == target) ? 1 : 0;
			}
			if (fclose(search_in) == EOF)
			{
				fprintf(stderr, "Error in closing file %s.\n", argv[i]);
				exit(EXIT_FAILURE);
			}
			printf("There are %d '%c's in %s.\n", num, target, argv[i]);
		}
	}
	printf("Done.\n");
	
	return 0;
}
