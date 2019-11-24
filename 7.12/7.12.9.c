//¡¶C Primer Plus¡·p215 7.12.9
#include <stdio.h>

int main(void)
{
	int max;
	scanf("%d", &max);
	
	int x;
	int y;
	for (x = max; x > 1; x--)
	{
		for (y = 2; y < x; y++)
		{
			if (x % y)
			{
				;
			}
			else
			{
				break; 
			}
			if (y + 1 == x)
			{
				printf("%d ", x); 
			}
		 } 
	}
	printf("2"); 
	
	return 0;
 } 
