//《C Primer Plus》p215 7.12.2
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	int i = 0;
	
	while ((ch = getchar()) != STOP)	//注意括号！！！ 
	{
		i++;
		if (i >= 8)
		{
			printf("\n");
			i = 0;
		}
		printf("%c-%d ", ch, ch);
	 } 
	 
	return 0;
 } 
 
//这个程序并不需要用到字符数组 
