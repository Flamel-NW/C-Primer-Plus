//¡¶C Primer Plus¡·p437 13.11.3
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NAME_LENGTH 10

void fcopy(FILE * fs, FILE * fa);
void fcopy_u(FILE * fs, FILE * fa);
int main(void)
{
	FILE * file_r, * file_w;
	char temp[] = "temp.txt";
	char file[NAME_LENGTH];
	
	printf("Enter name of file:");
	scanf("%s", file);
	
	if ((file_r = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", file);
		exit(EXIT_FAILURE);
	}
	if ((file_w = fopen(temp, "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", temp);
		exit(EXIT_FAILURE);
	}
	
	fcopy(file_r, file_w);
	
	fclose(file_r);
	fclose(file_w);
	
	file_r = fopen(temp, "r");
	file_w = fopen(file, "w");
	
	fcopy_u(file_r, file_w);
	
	fclose(file_r);
	fclose(file_w);
	
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
	if (ferror(fs) != 0)
	{
		fprintf(stderr, "Error in reading file.\n");
	}
	if (ferror(fa) != 0)
	{
		fprintf(stderr, "Error in writing file.\n");
	}
}

void fcopy_u(FILE * fs, FILE * fa)
{
	int ch;
	while ((ch = getc(fs)) != EOF)
	{
		putc(toupper((char) ch), fa);
	}
	if (ferror(fs) != 0)
	{
		fprintf(stderr, "Error in reading file.\n");
	}
	if (ferror(fa) != 0)
	{
		fprintf(stderr, "Error in writing file.\n");
	}
}
