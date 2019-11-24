//¡¶C Primer Plus¡·p437 13.11.1 
#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 10

int main(void)
{
	int ch;
	char filename[NAME_LENGTH];
	FILE * fp;
	unsigned long count = 0;
	
	printf("Please enter the filename:");
	scanf("%s", filename);
	
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s has %lu characters\n", filename, count);
	
	return 0;
}
