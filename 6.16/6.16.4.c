//¡¶C Primer Plus¡·p175 6.16.4
#include <stdio.h>
#define ROWS 6

int main(void)
{
	int row;
	int i;
	char ch = 'A';
	
	for (row = 0; row < ROWS; row++)
	{
		for (i = 0; i < (1 + row); i++, ch++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	
	return 0;
 } 
