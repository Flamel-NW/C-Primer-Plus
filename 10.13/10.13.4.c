//¡¶C Primer Plus¡·p318 10.13.4
#include <stdio.h>
#define SIZE 5

int max(double * arr);
int main(void)
{
	double nums[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
	
	printf("%d", max(nums));
	
	return 0;
}

int max(double * arr)
{
	double m;
	int n;
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] > m)
		{
			m = arr[i];
			n = i;
		}
	 }  
	
	return n;
}
