//¡¶C Primer Plus¡·p431 13.11.5 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096

void append(FILE * souece, FILE * dest);
int main (int argc, char * argv [])
{
	FILE * fa, * fs;
	int ch;
	
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if (!strcmp(argv[1], argv[2]))
	{
		fprintf(stderr, "Can't copy file to itself.\n");
		exit(EXIT_FAILURE);
	}
	
	if (!(fa = fopen(argv[1], "a+")))
	{
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE))
	{
		fputs("Can't create output buffer.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	if (!(fs = fopen(argv[2], "r")))
	{
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fs, NULL, _IOFBF, BUFSIZE))
	{
		fputs("Can't create input buffer.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	append(fs, fa);
	if (ferror(fs))
	{
		fprintf(stderr, "Error in reading file %s.\n", argv[1]);
	}
	if (ferror(fa))
	{
		fprintf(stderr, "Error in writing file %s.\n", argv[2]);
	}
	fclose(fs);
	printf("File %s appended.\n", argv[1]);
	
	rewind(fa);
	printf("%s contents:\n", argv[2]);
	while ((ch = getc(fa)) != EOF)
	{
		putchar(ch);
	}
	printf("\nDone displaying.\n");
	fclose(fa);
	
	return 0;
}

void append(FILE * source, FILE  * dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
	{
		fwrite(temp, sizeof(char), bytes, dest);
	}
}
