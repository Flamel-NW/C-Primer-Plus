//¡¶C Primer Plus¡·p437 13.11.10
#include <stdio.h>
#include <stdlib.h>
#define NAME 16
#define LENGTH 512

int main(void)
{
	FILE * fp;
	long int position;
	char ch;
	char name[NAME];
	
	printf("Enter the file name:");
	scanf("%s", name);
	
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", name);
		exit(EXIT_FAILURE);
	}
	
	printf("Enter a position of the file to print (<0 or nonnumeric character to terminate):");
	while ((scanf("%ld", &position)) == 1 && position >= 0)
	{
		while ((ch = getc(fp)) != '\n' && (int) ch != EOF)
		{
			putc(ch, stdout);
		}
		printf("\nEnter another position of the file to print (<0 or nonnumeric character to terminate):");
	}
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing \"%s\" file.\n", name);
		exit(EXIT_FAILURE);
	}
	printf("Done.\n");
	
	return 0;
}
