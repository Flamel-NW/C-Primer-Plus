//¡¶C Primer Plus¡·p175 6.16.12
#include <stdio.h>

int main(void)
{
	int i;
	float x;
	float sum1, sum2;
	int sign;
	
	while (scanf("%d", &i) == 1 && i > 0)
	{
		sum1 = 0;
		sum2 = 0;
		sign = 1;
		
		for (x = 1; x <= i; x++, sign *= -1)
		{
			sum1 += 1.0 / x;
			sum2 += sign * (1.0 / x);
		}
		printf("sum1 = %f\nsum2 = %f\n", sum1, sum2);
	}
	printf("Done");
 } 
