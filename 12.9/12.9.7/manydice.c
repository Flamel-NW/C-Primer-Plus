//°∂C Primer Plus°∑p394 12.9.7
//mandydice.c
//”Îdiceroll.c“ª∆±‡“Î
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
	int sets;
	int sides, dice;
	int status;
	int * roll;
	
	srand((unsigned int) time(NULL));
	printf("Enter an number of sets, enter q to stop:");
	while (scanf("%d", &sets) == 1)
	{
		if (sets < 1)
		{
			printf("Need at least 1 set.\n");
			printf(" Let\'s begin again.\n");
			printf("Enter an number of sets, enter q to stop:");
			continue;
		}
		roll = (int *) malloc(sets * sizeof(int));
		
		printf("How many sizes and how many dice?");
		if ((status = scanf("%d%d", &sides, &dice)) != 2)
		{
			if (status == EOF)
			{
				break;
			}
			else
			{
				printf("You should have entered tow integers.");
				printf(" Let\'s begin again.\n");
				while (getchar() != '\n')
				{
					continue;
				}
				printf("Enter an number of sets, enter q to stop:");
				continue;
			}
		}
		
		int i;
		for (i = 0; i < sets; i++)
		{
			roll[i] = roll_n_dice(dice, sides);
		}
		
		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		for(i = 0; i < sets; i++)
		{
			printf("%4d", roll[i]);
			if (i % 6 == 5)
			{
				printf("\n");
			}
		}
		free(roll);
		
		printf("How many sets? Enter q to stop:");
	}
	printf("The rollem() function was called %d times.\n", roll_count);
	printf("GOOD FORTUNE TO YOU!\n");
	
	return 0;
}
