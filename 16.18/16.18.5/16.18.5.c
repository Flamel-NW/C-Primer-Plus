//¡¶C Primer Plus¡·p564 16.18.5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10

void random_print(const int nums[], int n, int times);

int main(void)
{
	int array[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	random_print(array, SIZE, 4);
	
	return 0;
}

void random_print(const int nums[], int n, int times)
{
	int temp[n];
	memcpy(temp, nums, n * sizeof(int));
	
	int i, j;
	for (i = 0; i < times; i++)
	{
		srand((unsigned int) time(0));
		j = rand() % n;
		printf("%d ", temp[j]);
		for ( ; j < n; j++)
		{
			if (j == n - 1)
			{
				temp[j] = '\0';
			}
			else
			{
				temp[j] = temp[j + 1];
			}
		}
		n--;
	}
}
