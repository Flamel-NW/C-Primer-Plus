//¡¶C Primer Plus¡·p372 11.13.15
#include <stdio.h>
#include <string.h>
#define SIZE 5

int my_atoi(char string[]);
int main(void)
{
	char digit[SIZE] = "12";
	char str[SIZE] = "1bc";
	
	printf("%d\n", my_atoi(digit));
	printf("%d\n", my_atoi(str));
	
	return 0;
}

int my_atoi(char string[])
{
	int i;
	int num; 
	
	for (i = 0; isblank(string[i]); i++)
	{
		continue;
	}
	
	for (num = 0; isdigit(string[i]); i++, num++)
	{
		continue;
	}
	if (string[i])
	{
		num = 0;
	}
	
	return num;
}
