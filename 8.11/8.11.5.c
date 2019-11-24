//¡¶C Primer Plus¡·p242 8.11.5
#include <stdio.h>

int main(void)
{
	int guess = 50;
	int max = 100;
	int min = 1;
	char response1;
	char response2;
	
	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Response with a y if my guess is right and with an n if it is wrong.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response1 = getchar()) != 'y')
	{
		while (getchar() != '\n')
		{
			continue;
		}
		if (response1 == 'n')
		{
			printf("My guess is smaller or bigger?\n");
			printf("Response with a s if my guess is smaller and with an b if it is bigger.\n");
			response2 = getchar();
			if (response2 == 'b')
			{
				max = guess;
				guess = (guess + min) / 2;
				printf("Well, then, is it %d?\n", guess);
			}
			else if (response2 == 's')
			{
				min = guess;
				guess = (guess + max) / 2;
				printf("Well, then, is it %d?\n", guess);
			}
		}
		else
		{
			printf("Sorry, I under stand you.\n");
			continue;
		}
		while (getchar() != '\n')
		{
			continue;
		}
	}
	printf("I knew I could do it!\n");
	
	return 0;
 } 
