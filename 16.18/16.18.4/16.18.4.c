//《C Primer Plus》p565 16.18.4
#include <stdio.h>
#include <time.h>

void delay(double time); 	// 相当于一个sleep ()函数 

int main(void)
{
	double time = 10.0;
	
	delay(time);
	puts("Time is out.");
	
	return 0;
}

void delay(double time)
{
	double a = ((double) clock()) / CLOCKS_PER_SEC;
	
	while (((double) clock()) / CLOCKS_PER_SEC < time)
	{
		continue;
	}
}
