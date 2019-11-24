//¡¶C Primer Plus¡·p372 11.13.10
#include <stdio.h>
#include <string.h>
#define SIZE 30

void delete_blank(char string[]);
int main(void)
{
	char str[SIZE];
	
	fgets(str, SIZE, stdin);
	while (str[0] != '\n')
	{
		delete_blank(str);
		fputs(str, stdout);
		fgets(str, SIZE, stdin);
	}
	
	return 0;
}

void delete_blank(char string[])
{
	int i, j;
	
	for (i = 0; string[i]; i++)
	{
		if (isblank(string[i]))
		{
			for (j = i; string[j]; j++)
			{
				string[j] = string[j + 1];
			}
		}
	}
}
