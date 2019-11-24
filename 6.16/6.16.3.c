//¡¶C Primer Plus¡·p174 6.16.3
#include <stdio.h>
#define ROWS 6

int main()
{
	int row;
	char ch;
	
	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'F'; ch >= ('F' - row); ch--)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
	
	return 0;
 } 
