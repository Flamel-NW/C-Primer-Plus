//¡¶C Primer Plus¡·p175 6.16.11
#include <stdio.h>

int main(void)
{
	int numbers[8];
	int i;
	
	for (i = 0; i <= 7; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	for (i = 7; i >= 0; i--)
	{
		printf("%d ", numbers[i]);
	}
	
	return 0;
 } 
