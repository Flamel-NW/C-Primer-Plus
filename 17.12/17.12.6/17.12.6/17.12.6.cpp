// 17.12.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//《C Primer Plus》p631 17.12.6

#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define SIZE 5

bool search(int nums[], int n, int searchfor);

int main()
{
	int numbers[SIZE] = { 1, 4, 5, 6, 7 };
	if (search(numbers, SIZE, 4))
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}

	return 0;
}

bool search(int nums[], int n, int searchfor)
{
	int bottom = 1;
	int top = n;
	
	while (top != bottom)
	{
		if (searchfor == nums[(top - 1 + bottom - 1) / 2])
		{
			return true;
		}
		if (searchfor > nums[(top - 1 + bottom - 1) / 2])
		{
			if (top - bottom == 1)
			{
				return false;
			}
			bottom = (top + bottom) / 2;
		}
		else
		{
			top = (top + bottom) / 2;
		}
	}

	return false;
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
