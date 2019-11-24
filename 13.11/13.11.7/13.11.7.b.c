//¡¶C Primer Plus¡·p437 13.11.7.b
#include <stdio.h>
#include <stdlib.h>
#define SIZE 512
#define NAME 16

int main(void)
{
	FILE * file1, * file2;
	char name1[NAME];
	char name2[NAME];
	char temp[SIZE];
	int i;
	
	printf("Enter names of file1 and file2:");
	scanf("%s%s", name1, name2);
	
	if ((file1 = fopen(name1, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", name1);
		exit(EXIT_FAILURE);
	}
	if ((file2 = fopen(name2, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s.\n", name2);
		exit(EXIT_FAILURE);
	}
	
	while (1)
	{
		if (fgets(temp, SIZE, file1) != NULL)
		{
			for (i = 0; i < SIZE; i++)
			{
				temp[i] = (temp[i] == '\n') ? '\0' : temp[i];
			}
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
		fprintf(stderr, "Error in closing file %s.\n", name1);
		exit(EXIT_FAILURE);
	}
	if (fclose(file2) == EOF)
	{
		fprintf(stderr, "Error in closing file %s.\n", name2);
		exit(EXIT_FAILURE);
	}
	printf("Done.\n");
	
	return 0;
}
