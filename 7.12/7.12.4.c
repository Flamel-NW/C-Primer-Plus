//《C Primer Plus》p215 7.12.4
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	int replace = 0;
	
	while ((ch = getchar()) != STOP)
	{
		if ('.' == ch)
		{
			printf("!");
			replace++;
		}
		else if ('!' == ch)
		{
			printf("!!");
			replace++;
		}
		else
		{
			printf("%c", ch);
		}
	}
	printf("\n转换次数为：%d", replace);
	
	return 0;
}
