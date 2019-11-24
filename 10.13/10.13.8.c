//¡¶C Primer Plus¡·p318 10.13.8
#include <stdio.h>
#define SIZE 7

void copy_arr(double * arr2, double * arr1, int n);
void print_arr(double * arr, int n);
int main(void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	double target[3];
	
	copy_arr(target, source + 2, 3);
	
	print_arr(target, 3);
	
	return 0;
}

void copy_arr(double * arr2, double * arr1, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr2[i] = arr1[i];
	}
}

void print_arr(double * arr, int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		printf("%.2f ", arr[i]); 
	 } 
	printf("\n");
 } 	
