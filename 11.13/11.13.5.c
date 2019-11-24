//��C Primer Plus��p372 11.13.5
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

/* 	����������ĵ�һ���βθ�Ϊ��const char string[]���ᾯ��
	��Ϊ�����ķ���ֵ��һ��ָ��string[i]����ָͨ�벢�ҿ���ͨ�����ָ��ı�string[i]
	����Ȼ��constì��
	����������������ķ���ֵ��Ϊһ��ָ��const��ָ��		*/ 
