//��C Primer Plus��p175 6.16.6
#include <stdio.h>

int main(void)
{
	int max;
	int min;
	int number;

	
	printf("������������ޣ�");
	scanf("%d", &min);	
	
	printf("������������ޣ�");
	scanf("%d", &max);
	
	for (number = min; number <= max; number++)
	{
		printf("%6d%6d%6d\n", number, number * number, number * number *number);
	}
	
	return 0;
 } 
