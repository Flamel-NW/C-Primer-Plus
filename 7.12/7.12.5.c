//《C Primer Plus》p215 7.12.5
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	int replace = 0;
	
	while ((ch = getchar()) != STOP)
	{
		switch (ch)
		{
			case '.':
				printf("!");
				replace++;
				break;
			case '!':
				printf("!!");
				replace++;
				break;
			default:
				printf("%c", ch);
		}
	}
	printf("\n转换次数为：%d", replace);
	
	return 0;
}
