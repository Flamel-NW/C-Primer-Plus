//��C Primer Plus��p134 5.11.5
#include <stdio.h>

int main()
{
	int count = 0;
	int sum = 0;
	int times;
	
	scanf("%d", &times); 
	while (count++ < times)
	{
		sum += count;
	}
	printf("sum = %d\n", sum);
	
	return 0;
 } 
 
// �������õĴ�����#include��while���һ�� 
