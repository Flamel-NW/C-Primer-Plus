//¡¶C Primer Plus¡·p134  5.11.2
#include<stdio.h>
#define MINUTE_PER_HOUR 60

int main()
{
	int time;
	int hour;
	int minute;
	
	scanf("%d", &time);
	
	while(time > 0)
	{
		hour = time / MINUTE_PER_HOUR;
		minute = time % MINUTE_PER_HOUR;
		printf("%d minutes are %d hours, %d minutes", time, hour, minute);
		scanf("%d", &time);
	}
	printf("bye!");
	
	return 0;
}
