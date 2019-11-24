//¡¶C Primer Plus¡·p410 12.9.5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void sort_str(int string[], int n);
int main(void)
{
	int rands[SIZE];
	
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < SIZE; i++)
	{
		rands[i] = (rand() % 10) + 1;
	}
	
	sort_str(rands, SIZE);
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%3d", rands[i]);
		printf("%c", (i % 10 == 9) ? '\n' : ' ');
	}
	
	return 0;
}

void sort_str(int string[], int n)
{
	int temp;
	
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (string[i] < string[j])
			{
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}
}
