// 17.12.5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//《C Primer Plus》p631 17.12.5
// 与17.12.5_stack.cpp一起编译

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "17.12.5_stack.h"
#define SIZE 30

char * s_gets(char * st, int n);

int main()
{
	char string[SIZE];
	s_gets(string, SIZE);

	Item temp;
	Stack str;
	char ch;
	InitializeStack(&str);

	int i;
	for (i = 0; i < SIZE && string[i] != '\0'; i++)
	{
		temp = (Item)string[i];
		if (!FullStack(&str))
		{
			Push(temp, &str);
		}
	}
	while(!EmptyStack(&str))
	{
		Pop(&temp, &str);
		ch = (char)temp;
		putchar(ch);
	}

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}

	return ret_val;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
