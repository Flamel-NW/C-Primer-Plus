//《C Primer Plus》p215 7.12.6
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch1, ch2;
	int n_ei = 0;
	
	while ((ch1 = getchar()) != STOP)
	{
		if ('i' == ch1 && 'e' == ch2)
		{
			n_ei++;
		}
		ch2 = ch1;
	}
	printf("\"ei\"出现的次数为：%d", n_ei);
	
	return 0;
 } 
