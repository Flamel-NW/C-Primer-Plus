//《C Primer Plus》p134 5.11.5
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
 
// 养成良好的代码风格：#include和while后空一格 
