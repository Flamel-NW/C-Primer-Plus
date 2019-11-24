//《C Primer Plus》p490 14.18.2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 10
#define MONTHS 12

struct month
{
	char n_month[SIZE];
	char s_month[SIZE];
	int days_month;
	int No_; 
};

bool isleap(int year);
int days(int date, char month[], int the_year);

int main(void)
{
	int in_date; 
	char in_month[SIZE];
	int in_year;
	
	printf("请输入日期：");
	if (scanf("%d%s%d", &in_date, in_month, &in_year) == 0)
	{
		fprintf(stderr, "输入错误！");
		exit(EXIT_FAILURE);
	}
	
	printf("今年已过去%d天。", days(in_date, in_month, in_year));
	
	return 0;
}

bool isleap(int year)
{
	bool re_leap;
	if (year % 4 == 0 && year % 400 != 0)
	{
		re_leap = true;
	}
	else
	{
		re_leap = false;
	}
	
	return re_leap;
}

int days(int date, char month[], int the_year)
{ 
	int days_Feb;
	if (isleap(the_year))
	{
		days_Feb = 29;
	}
	else
	{
		days_Feb = 28;
	}
	
	struct month year[MONTHS] =
	{
		{ "January", "Jan.", 31, 1 },
		{ "February", "Feb.", days_Feb, 2 },
		{ "March", "Mar.", 31, 3 },
		{ "April", "Apr.", 31, 4 },
		{ "May", "\0", 31, 5 },
		{ "June", "\0", 31, 6 },
		{ "July", "\0", 31, 7 },
		{ "August", "Aug.", 31, 8 },
		{ "September", "Sept.", 30, 9 },
		{ "October", "Oct.", 31, 10 },
		{ "November", "Nov.", 30, 11 },
		{ "December", "Dec.", 31, 12 },
	};
	
	int i;
	for (i = 0; i < MONTHS; i++)
	{
		if (strcmp(month, year[i].n_month) == 0 ||
			strcmp(month, year[i].s_month) == 0 ||
			strtol(month, NULL, 10) == year[i].No_)
		{
			break;
		}
		if (i == MONTHS - 1)
		{
			fprintf(stderr, "月份输入错误！");
			exit(EXIT_FAILURE);
		}
	}
	
	if (date > year[i].days_month)
	{
		fprintf(stderr, "日期输入错误！");
		exit(EXIT_FAILURE);
	}
	
	int re_days = date; 
	int j;
	for (j = 0; j < i; j++)
	{
		re_days += year[j].days_month;
	}
	
	return re_days;
}
