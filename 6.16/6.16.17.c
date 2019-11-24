//¡¶C Primer Plus¡·p176 6.16.17
#include <stdio.h>
#define PRIZE 100
#define WITHDRAW 10

int main(void)
{
	int year;
	float deposit = PRIZE;
	for (year = 0; deposit > 0; year++)
	{
		deposit -= 10;
		deposit *= 1.08;
	}
	printf("%d", year);
	
	return 0;
}
