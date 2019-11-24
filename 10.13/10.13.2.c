//¡¶C Primer Plus¡·p318 10.13.2
#include <stdio.h>
#define SIZE 5

void copy_arr(double * arr2, double * arr1, int n);
void copy_ptr(double * arr2, double * arr1, int n);
void copy_ptrs(double * arr2, double * arr1, double * ptr_end);
void print_arr(double * arr);
int main(void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];
	
	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	copy_ptrs(target3, source, source + SIZE);
	
	print_arr(source);
	print_arr(target1);
	print_arr(target2);
	print_arr(target3);
	
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

void copy_ptr(double * arr2, double * arr1, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		*(arr2 + i) = *(arr1 + i);
	}
}

void copy_ptrs(double * arr2, double * arr1, double * ptr_end)
{
	for (; arr1 < ptr_end; arr1++, arr2++)
	{
		*arr2 = *arr1;
	}
}

void print_arr(double * arr)
{
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", arr[i]); 
	 } 
	printf("\n");
 } 
