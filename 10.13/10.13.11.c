//¡¶C Primer Plus¡·p318 10.13.11
#include <stdio.h>
#define ROWS 3
#define COLS 5

void double_arr(int arr[][COLS], int rows);
void print_arr(int arr[][COLS], int rows);
int main(void)
{
	int arr[ROWS][COLS] =
	{
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 }
	};
	
	double_arr(arr, ROWS);
	
	print_arr(arr, ROWS);
	
	return 0;
}

void double_arr(int arr[][COLS], int rows)
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] *= 2;
		}
	}
}

void print_arr(int arr[][COLS], int rows)
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			printf("%5d ", arr[i][j]);
		}
		putchar('\n');
	}
}
