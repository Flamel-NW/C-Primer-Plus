//¡¶C Primer Plus¡·p371 11.13.2
#include <stdio.h>
#include <ctype.h>
#define SIZE 10

void get1(char string[], int n);
int main(void)
{
	char str[SIZE];
	
	get1(str, SIZE);
	fputs(str, stdout);
	
	return 0;
}

void get1(char string[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (isspace(string[i] = getchar()))
		{
			break;
		}
	}
}
