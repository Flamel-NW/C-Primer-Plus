//《C Primer Plus》p372 11.13.11 
#include <stdio.h>
#include <string.h>
#define ROWS 10
#define COLS 30

void stsrtb(char * strings [], int num);
void stsrtc(char * strings [], int num);
void stsrtd(char * strings [], int num);
void put_ptrs(char * ptr [], int num); 
void put_strs(char str[][COLS], int num); 
void get_word(char word[], char string[]);
int main(void)
{
	char input[ROWS][COLS];
	char * ptstr[COLS];
	int rows;
	char option;
	
	for (rows = 0; rows < ROWS && fgets(input[rows], COLS, stdin) != NULL; rows++)
	{
		ptstr[rows] = input[rows];
	}
	
	while (1)
	{
		printf("菜单：\n");
		printf("a. 打印源字符串列表				b. 以ASCII中的顺序打印字符串\n");
		printf("c. 按长度递增顺序打印字符串		d. 按字符串中第1个单词的长度打印字符串\n");
		printf("q. 退出\n");
		
		if ((option = getchar()) == 'q')
		{
			break;
		}
		while (getchar() != '\n')
		{
			continue;
		}
		
		switch (option)
		{
			case 'a':
				put_strs(input, rows);
				break;
			case 'b':
				stsrtb(ptstr, rows);
				put_ptrs(ptstr, rows);
				break;
			case 'c':
				stsrtc(ptstr, rows);
				put_ptrs(ptstr, rows);
				break;
			case 'd':
				stsrtd(ptstr, rows);
				put_ptrs(ptstr, rows);
				break;
		}
	}
	
	return 0;
}

void stsrtb(char * strings [], int num)
{
	char * temp;
	int top, seek;
	
	for (top = 0; top < num - 1; top++)
	{
		for (seek = top + 1; seek < num; seek++)
		{
			if (strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

void stsrtc(char * strings [], int num)
{
	char * temp;
	int top, seek;
	
	for (top = 0; top < num - 1; top++)
	{
		for (seek = top + 1; seek < num; seek++)
		{
			if (strlen(strings[top]) > strlen(strings[seek]))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

void stsrtd(char * strings [], int num)
{
	char * temp;
	int top, seek;
	char word1[COLS];
	char word2[COLS];
	
	for (top = 0; top < num - 1; top++)
	{
		for (seek = top + 1; seek < num; seek++)
		{
			get_word(word1, strings[top]);
			get_word(word2, strings[seek]);
			if (strlen(word1) > strlen(word2))
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}

void put_ptrs(char * ptr [], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		fputs(ptr[i], stdout);
	}
}

void put_strs(char str[][COLS], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		fputs(str[i], stdout);
	}
}

void get_word(char word[], char string[])
{
	int i, j;
	
	for (i = 0; isblank(string[i]); i++)
	{
		continue;
	}
	for (j = 0; isalpha(string[i]); i++, j++)
	{
		word[j] = string[i];
	}
}
