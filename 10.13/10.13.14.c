//¡¶C Primer Plus¡·p318 10.13.13
#include <stdio.h>
#define ROWS 3
#define COLS 5

void scan_arr(int rows, int cols, double arr[rows][cols]);
double row_average(int cols, double row[cols]);
double all_average(int rows, int cols, double arr[rows][cols]);
double max_element(int rows, int cols, double arr[rows][cols]);
int main(void)
{
	double arr[ROWS][COLS];
	
	scan_arr(ROWS, COLS, arr);
	
	int row;
	for (row = 0; row < ROWS; row++)
	{
		printf("b.%5.2f\n", row_average(COLS, arr[row]));
	 } 	
	
	printf("\nc.%5.2f\n", all_average(ROWS, COLS, arr));
	
	printf("\nd.%5.2f\n", max_element(ROWS, COLS, arr));
	
	return 0;
 } 

void scan_arr(int rows, int cols, double arr[rows][cols])
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			scanf("%lf", &arr[i][j]);
		}
		getchar();
	}
}

double row_average(int cols, double row[cols])
{
	int sum = 0;
	
	int i;
	for (i = 0; i < cols; i++)
	{
		sum += row[i];
	}
	
	return (sum / COLS);
}

double all_average(int rows, int cols, double arr[rows][cols])
{
	int sum = 0;
	
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			sum += arr[i][j];
		}
	}
	
	return (sum / (ROWS * COLS));
}

double max_element(int rows, int cols, double arr[rows][cols])
{
	int m = arr[0][0];
	
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			if (arr[i][j] > m)
			{
				m = arr[i][j];
			}
		}
	}
	
	return m;
}
