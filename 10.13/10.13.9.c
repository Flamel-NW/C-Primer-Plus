//¡¶C Primer Plus¡·p318 10.13.9
#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy_arr(int rows, int cols, double arr1[rows][cols], double arr2[rows][cols]);
void print_arr(int rows, int cols, double arr[rows][cols]);
int main(void)
{
	double source[ROWS][COLS] =
	{
		{ 1.1, 2.2, 3.3, 4.4, 5.5 },
		{ 1.1, 2.2, 3.3, 4.4, 5.5 },
		{ 1.1, 2.2, 3.3, 4.4, 5.5 }
	};
	
	double target[ROWS][COLS];
	
	copy_arr(ROWS, COLS, source, target);
	print_arr(ROWS, COLS, source);
	print_arr(ROWS, COLS, target);
	
	return 0;
}

void copy_arr(int rows, int cols, double arr1[rows][cols], double arr2[rows][cols])
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr2[i][j] = arr1[i][j];
		}
	}
}

void print_arr(int rows, int cols, double arr[rows][cols])
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%.2f ", arr[i][j]);
		}
		putchar('\n');
	}
}
