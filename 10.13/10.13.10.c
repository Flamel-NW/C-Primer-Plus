//¡¶C Primer Plus¡·p318 10.13.10
#include <stdio.h>
#define SIZE 4

void add_arrs(int arr1[], int arr2[], int sum[], int n);
void print_arr(int arr[], int n);
int main(void)
{
	int add1[SIZE] = {1, 2, 3, 4};
	int add2[SIZE] = {1, 2, 3, 4};
	int sum[SIZE];
	
	add_arrs(add1, add2, sum, SIZE);
	
	print_arr(sum, SIZE);
	
	return 0;
}

void add_arrs(int arr1[], int arr2[], int sum[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		sum[i] = arr1[i] + arr2[i];
	}
}

void print_arr(int arr[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]); 
	 } 
	printf("\n");
}
