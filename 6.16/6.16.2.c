//¡¶C Primer Plus¡·p174 6.16.2
#include <stdio.h>
#define ROWS 5

int main()
{
	int row;
	int length;
	
	for (row = 1; row <= ROWS; row++)
	{
		for (length = 1; length <= row; length++)
		{
			printf("$");
		}
		printf("\n");
	}
	
	return 0;
 } 
