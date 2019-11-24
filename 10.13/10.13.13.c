//¡¶C Primer Plus¡·p318 10.13.13
#include <stdio.h>
#define ROWS 3
#define COLS 5

void scan_arr(double arr[][COLS]);
double row_average(double row[]);
double all_average(double arr[][COLS]);
double max_element(double arr[][COLS]);
int main(void)
{
	double arr[ROWS][COLS];
	
	scan_arr(arr);
	
	int row;
	for (row = 0; row < ROWS; row++)
	{
		printf("b.%5.2f\n", row_average(arr[row]));
	 } 	
	
	printf("\nc.%5.2f\n", all_average(arr));
	
	printf("\nd.%5.2f\n", max_element(arr));
	
	return 0;
 } 

void scan_arr(double arr[][COLS])
{
	int i, j;
	
	for (i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			scanf("%lf", &arr[i][j]);
		}
		getchar();
	}
}

double row_average(double row[])
{
	int sum = 0;
	
	int i;
	for (i = 0; i < COLS; i++)
	{
		sum += row[i];
	}
	
	return (sum / COLS);
}

double all_average(double arr[][COLS])
{
	int sum = 0;
	
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	
	return (sum / (ROWS * COLS));
}

double max_element(double arr[][COLS])
{
	int m = arr[0][0];
	
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (arr[i][j] > m)
			{
				m = arr[i][j];
			}
		}
	}
	
	return m;
}
