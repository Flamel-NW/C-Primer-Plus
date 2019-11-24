//¡¶C Primer Plus¡·p371 11.13.3
#include <stdio.h>
#include <ctype.h>
#define SIZE 10

void get1(char string[], int n);
int main(void)
{
	char str[SIZE];
	
	get1(str, SIZE);
	fputs(str, stdout);
	
	char leave[SIZE];
	fgets(leave, SIZE, stdin);
	fputs(leave, stdout);
	
	return 0;
}

void get1(char string[], int n)
{
	int i = 0;
	
	while (isblank(string[i] = getchar()))
	{
		continue;
	}
	for (i = 1; i < n; i++)
	{
		if (isspace(string[i] = getchar()))
		{
			while (getchar() != '\n')
			{
				continue;
			}
			break;
		}
	}
}
