//《C Primer Plus》p175 6.16.7
#include <stdio.h>
#include <string.h>

int main(void)
{
	char ch[20];
	int i;
	
	scanf("%s", ch);
	
	for (i = strlen(ch) - 1; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}
	
	return 0;
 } 
 
/* 这道题说要将该单词录入一个字符数组，可这明显已经构成一个字符串？？所以第12行才要减一，以跳过字符串末尾的空字符\0
 	那正确应该怎么做呢？？用getchar()吗？？  */ 
