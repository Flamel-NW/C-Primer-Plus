//¡¶C Primer Plus¡·p437 13.11.4
#include <stdio.h>
#include <stdlib.h>

void fcopy(FILE * fs, FILE * fa);
int main(int argc, char * argv [])
{
	FILE * file [argc];
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int i;
	for (i = 0; i < argc - 1; i++)
	{
		if ((file[i] = fopen(argv[i + 1], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s.\n", argv[i + 1]);
			exit(EXIT_FAILURE);
		}
		fcopy(file[i], stdout);
		fprintf(stdout, "\n");
		fclose(file[i]);
	}
	printf("Done.\n");
	
	return 0;
}

void fcopy(FILE * fs, FILE * fa)
{
	int ch;
	while ((ch = getc(fs)) != EOF)
	{
		putc((char) ch, fa);
	}
	if (ferror(fs))
	{
		fprintf(stderr, "Error in reading file.\n");
	}
	if (ferror(fa))
	{
		fprintf(stderr, "Error in writing file.\n");
	}
}

