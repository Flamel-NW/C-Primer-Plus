//¡¶C Primer Plus¡·p175 6.16.10
#include <stdio.h>

int main(void)
{
	int min;
	int max;
	int i;
	int sum = 0;
	
	printf("Enter lower and upper integer limits:");

	
	for (; scanf("%d %d", &min, &max) == 2 && max - min > 0; sum = 0)
	{
		for (i = min; i <= max; i++)
		{
			sum += i * i;
		}
		printf("The sums of the squares from %d to %d is %d\n", min * min, max * max, sum);
		printf("Enter next set of limits:");
	}
	printf("Done");
	
	return 0;
 } 
