//¡¶C Primer Plus¡·p437 13.11.6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(void)
{
	FILE * in, * out;
	int ch;
	char name_i[LEN];
	char name_o[LEN];
	int count = 0;
	
	printf("Enter name of file:");
	scanf("%s", name_i);
	
	if ((in = fopen(name_i, "r")) == NULL)
	{
		printf("Can't open %s\n", name_i);
		exit(EXIT_FAILURE);
	}
	
	strncpy(name_o, name_i, LEN - 5);
	name_o[LEN - 5] = '\0';
	strcat(name_o, ".red");
	
	if ((out = fopen(name_o, "w")) == NULL)
	{
		printf("Can't open %s\n", name_o);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(in)) != EOF)
	{
		if (!(count++ % 3))
		{
			putc(ch, out);
		}
	}
	
	if (fclose(in) || fclose(out))
	{
		fprintf(stderr, "Error in closing files.\n");
	}
	
	return 0;
}
