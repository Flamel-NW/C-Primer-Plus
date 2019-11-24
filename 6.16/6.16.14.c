//¡¶C Primer Plus¡·p175 6.16.14
#include <stdio.h>

int main()
{
	double number[8];
	double sum[8];
	int a;
	int b;
	
	for (a = 0; a < 8; a++)
	{
		scanf("%lf", &number[a]);
		sum[a] = 0;
		for (b = 0; b <= a; b++)
		{
			sum[a] += number[b];
		 } 
	}
	for (a = 0; a < 8; a++)
	{
		printf("%6.2f", number[a]);
	}
	printf("\n");
	for (b = 0; b < 8; b++)
	{
		printf("%6.2f", sum[b]);
	}
	
	return 0;
 } 
