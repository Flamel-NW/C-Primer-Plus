//《C Primer Plus》p490 14.18.1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MONTHS 12

struct month
{
	char n_month[SIZE];
	char s_month[SIZE];
	int days_month;
	int No_; 
};

int days(char month[]);

int main(void)
{
	char in_month[SIZE];
	
	printf("请输入月份名：");
	scanf("%s", in_month);
	
	printf("今年已过去%d天。", days(in_month));
	
	return 0;
}

int days(char month[])
{
	int re_days = 0;
	struct month year[MONTHS] =
	{
		{"January", "Jan.", 31, 1},
		{"February", "Feb.", 28, 2},
		{"March", "Mar.", 31, 3},
		{"April", "Apr.", 31, 4},
		{"May", "\0", 31, 5},
		{"June", "\0", 31, 6},
		{"July", "\0", 31, 7},
		{"August", "Aug.", 31, 8},
		{"September", "Sept.", 30, 9},
		{"October", "Oct.", 31, 10},
		{"November", "Nov.", 30, 11},
		{"December", "Dec.", 31, 12},
	};
	
	int i;
	for (i = 0; i < MONTHS; i++)
	{
		if (strcmp(month, year[i].n_month) == 0)
		{
			break;
		}
		if (i == MONTHS - 1)
		{
			fprintf(stderr, "输入错误！");
			exit(EXIT_FAILURE);
		}
	}
	
	int j;
	for (j = 0; j <= i; j++)
	{
		re_days += year[j].days_month;
	}
	
	return re_days;
}
