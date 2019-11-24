//¡¶C Primer Plus¡·p176 6.16.18
#include <stdio.h>
#define INITIAL 5
#define DUNBER_S_NUMBER 150 

int main(void)
{
	int friends = INITIAL;
	int week;
	printf("     week  friends\n");
	
	for (week = 1; friends <= DUNBER_S_NUMBER; week++)
	{
		friends--;
		friends *= 2;
		printf("%9d%9d\n", week, friends);
	}
	printf("Dr.Rabnud has already got enough friends.");
	
	return 0;
 } 
