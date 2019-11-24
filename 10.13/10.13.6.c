//¡¶C Primer Plus¡·p318 10.13.6
#include <stdio.h>
#define SIZE 5

void sort(double * arr);
void print_arr(double * arr);
int main(void)
{
	double nums[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};
	
	sort(nums);
	print_arr(nums);
	
	return 0;
}

void sort(double * arr)
{
	int i, j;
	double temp;
	
	for (i = 0; i < SIZE; i++)
	{
		for (j = i + 1; j < SIZE; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
 
//¾­µäµÄÊý×éÅÅÐòËã·¨¡ª¡ªÃ°ÅÝÅÅÐò 

void print_arr(double * arr)
{
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", arr[i]); 
	 } 
	printf("\n");
 } 
