//¡¶C Primer Plus¡·p318 10.13.5
#include <stdio.h>
#define SIZE 5

double max_min(double * arr);
int main(void)
{
	double nums[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
	
	printf("%.2f", max_min(nums));
	
	return 0;
}

double max_min(double * arr)
{
	double m = arr[0];
	double n = arr[0];
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] > m)
		{
			m = arr[i];
		}
		if (arr[i] < n)
		{
			n = arr[i];
		}
	 }  
	
	return (m - n);
}
