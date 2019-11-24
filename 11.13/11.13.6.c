//¡¶C Primer Plus¡·p372 11.13.6 
#include <stdio.h>
#include <stdbool.h>
#define SIZE 15

bool is_within(char string[], char target);
int main(void)
{
	char str[SIZE] = "I have a pen.";
	
	if (is_within(str, 'x'))
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}
	
	return 0;
}

bool is_within(char string[], char target)
{
	int i;
	bool within = false;
	
	for (i = 0; ; i++)
	{
		if (string[i] == target)
		{
			within = true;
			break;
		}
		if (!string[i])
		{
			break;
		}
	}
	
	return within;
}
