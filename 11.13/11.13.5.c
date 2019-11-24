//《C Primer Plus》p372 11.13.5
#include <stdio.h>
#define SIZE 15

char * strchr1(char string[], char target);
int main(void)
{
	char str[SIZE] = "I have a pen.";
	
	char * target = strchr1(str, 'a');
	putchar(*target);
	
	return 0;
}

char * strchr1(char string[], char target)
{
	int i;
	char * re = NULL;
	
	for (i = 0; ; i++)
	{
		if (string[i] == target)
		{
			re = string + i;
			break;
		}
		if (!string[i])
		{
			break;
		}
	}
	
	return re;
}

/* 	如果将函数的第一个形参改为“const char string[]”会警告
	因为函数的返回值是一个指向string[i]的普通指针并且可以通过这个指针改变string[i]
	这显然与const矛盾
	解决方法：将函数的返回值设为一个指向const的指针		*/ 
