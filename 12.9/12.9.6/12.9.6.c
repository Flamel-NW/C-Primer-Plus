//¡¶C Primer Plus¡·p410 12.9.6
#include <stdio.h>
#include <stdlib.h>
#define NUMBERS 1000
#define SIZE 10

int main(void)
{
	int num;
	int n[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	int i;
	srand(1);
	for (i = 0; i < NUMBERS; i++)
	{
		num = (rand() % 10) + 1;
		switch (num)
		{
			case 1:
				n[0]++;
				break;
			case 2:
				n[1]++;
				break;
			case 3:
				n[2]++;
				break;
			case 4:
				n[3]++;
				break;
			case 5:
				n[4]++;
				break;
			case 6:
				n[5]++;
				break;
			case 7:
				n[6]++;
				break;
			case 8:
				n[7]++;
				break;
			case 9:
				n[8]++;
				break;
			case 10:
				n[9]++;
				break;
		}
	}
	
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", n[i]);
	}
	
	return 0;
}
