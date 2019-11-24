//¡¶C Primer Plus¡·p372 11.13.9
#include <stdio.h>
#include <string.h>
#define SIZE 20

void reverse_sort(char string[]);
int main(void)
{
	char str[SIZE] = "I have a pen.";
	reverse_sort(str);
	
	fputs(str, stdout);
	
	return 0;
}

void reverse_sort(char string[])
{
	int length = strlen(string);
	char reverse_string[length];
	
	int i;
	for (i = 0; i < length; i++)
	{
		reverse_string[length - 1 - i] = string[i];
	}
	for (i = 0; i < length; i++)
	{
		string[i] = reverse_string[i];
	}
}
