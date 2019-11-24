//《C Primer Plus》p437 13.11.2
#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int main(int argc, char * argv [])
{
	FILE * fa, * fs;
	char temp[SIZE];
	size_t length;
	
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
	
	if ((fs = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((fa = fopen(argv[2], "wb")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while ((length = fread(temp, sizeof(char), SIZE, fs)) > 0)
	{
		fwrite(temp, sizeof(char), length, fa);
	}
	
	if (ferror(fs) != 0)
	{
		fprintf(stderr, "Error in reading file %s.\n", argv[1]);
	}
	if (ferror(fa) != 0)
	{
		fprintf(stderr, "Error in writing file %s.\n", argv[2]);
	}
	fclose(fs);
	fclose(fa);
	
	printf("Done.\n");
	
	return 0;
}

//看了答案。。。太难了！！ 
