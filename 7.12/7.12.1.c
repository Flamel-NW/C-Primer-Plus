//《C Primer Plus》p214 7.12.1
#include <stdio.h>
#define STOP '#'

int main(void)
{
	char ch;
	int n_spaces = 0;
	int n_lines = 0;
	int n_chars = 0;
	
	while ((ch = getchar()) != STOP)
	{
		n_chars++;
		if (ch == ' ')
		{
			n_spaces++;
		}
		if (ch == '\n')
		{
			n_lines++;
		}
	}
	printf("空格数：%d\n", n_spaces);
	printf("换行符数：%d\n", n_lines);
	printf("其他字符数：%d\n", n_chars - n_spaces - n_lines);
	
	return 0;
}
