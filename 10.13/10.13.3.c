//¡¶C Primer Plus¡·p318 10.13.3
#include <stdio.h>
#define SIZE 5

int max(int * arr);
int main(void)
{
	int nums[SIZE] = {1, 2, 3, 4, 5};
	
	printf("%d", max(nums));
	
	return 0;
}

int max(int * arr)
{
	int m;
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		if (arr[i] > m)
		{
			m = arr[i];
		}
	 }  
	
	return m;
}
