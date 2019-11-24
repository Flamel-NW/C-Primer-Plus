// 17.12.4_mall.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//《C Primer Plus》p631 17.12.4
// 17.12.4_mall.cpp -- 使用 Queue 接口
// 与17.12.4_Queue.cpp一起编译

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "17.12.4_queue.h"
#define MIN_PER_HR 60.0

bool newcustomer(double x);
Item customertime(long when);

int main()
{
	Queue line1;
	Queue line2;
	Item temp;
	int hours;
	int perhours;
	long cycle;
	long cyclelimit;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time1 = 0;
	int wait_time2 = 0;
	double min_per_cust;
	long line_wait = 0;

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int)time(0));
	puts("Case Study: Sigmund Lander\'s Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf_s("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	puts("Enter the number of customers per hour:");
	scanf_s("%d", &perhours);
	min_per_cust = MIN_PER_HR / perhours;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (QueueIsFull(&line1) && QueueIsFull(&line2))
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp = customertime(cycle);
				if (QueueItemCount(&line1) > QueueItemCount(&line2))
				{
					EnQueue(temp, &line2);
				}
				else
				{
					EnQueue(temp, &line1);
				}
			}
		}
		if (wait_time1 <= 0 && !QueueIsEmpty(&line1))
		{
			DeQueue(&temp, &line1);
			wait_time1 = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (wait_time2 <= 0 && !QueueIsEmpty(&line2))
		{
			DeQueue(&temp, &line2);
			wait_time2 = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}

		if (wait_time1 > 0)
		{
			wait_time1--;
		}
		if (wait_time2 > 0)
		{
			wait_time2--;
		}

		sum_line += QueueItemCount(&line1) + QueueItemCount(&line2);
	}

	if (customers > 0)
	{
		printf("customers accepted: %ld\n", customers);
		printf("  customers served: %ld\n", served);
		printf("      turnaways: %ld\n", turnaways);
		printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
		printf("average wait time: %.2f minutes\n", (double)line_wait / served);
	}
	else
	{
		puts("No customers!");
	}
	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Bye!");

	return 0;
}

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Item customertime(long when)
{
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
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
