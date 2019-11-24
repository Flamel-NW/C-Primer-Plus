//¡¶C Primer Plus¡·p134 5.11.3
#include<stdio.h>
#define DAY_PER_WEEK 7

int main()
{
	int day1, day2;
	int week;
	
	scanf("%d", &day1);
	
	while(day1 > 0)
	{
		week = day1 / DAY_PER_WEEK;
		day2 = day1 % DAY_PER_WEEK;
		printf("%d days are %d weeks, %d days", day1, week, day2);
		scanf("%d", &day1); 
	}
	printf("bye!");
	
	return 0;
 } 
