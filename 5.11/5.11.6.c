//¡¶C Primer Plus¡·p134 5.11.6
#include <stdio.h>

int main()
{
	int count = 0;
	int sum = 0;
	int times;
	
	scanf("%d", &times); 
	while (count++ < times)
	{
		sum += count * count;
	}
	printf("sum = %d\n", sum);
	
	return 0;
 } 
 

