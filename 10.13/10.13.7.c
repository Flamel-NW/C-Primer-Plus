//《C Primer Plus》p318 10.13.7
#include <stdio.h>
#define ROWS 2
#define COLS 2

void copy_arr(double * arr2, double * arr1, int n);
void print_arr(double * arr, int n);
int main(void)
{
	double source[ROWS][COLS] =
	{
		{ 1.1, 2.2 },
		{ 3.3, 4.4 }
	};
	double target[ROWS][COLS];
	
	int i;
	for (i = 0; i < ROWS; i++)
	{
		copy_arr(target[i], source[i], COLS);
	}
	
	for (i = 0; i < ROWS; i++)
	{
		print_arr(target[i], COLS);
	}
	
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
} 	//改进了这个常用函数 
