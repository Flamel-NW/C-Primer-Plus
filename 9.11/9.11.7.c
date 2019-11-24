//¡¶C Primer Plus¡·p276 9.11.7
#include <stdio.h>
#include <ctype.h>

void input(void);
int ch_n(char ch);
int main(void)
{
	input();
	
	return 0;
}

void input(void)
{
	int n_ch;
	char ch;
	
	while ((n_ch = getchar()) != EOF)
	{
		ch = n_ch;
		printf("%d ", ch_n(ch));
	}
}

int ch_n(char ch)
{
	int n;
	
	if (isalpha(ch))
	{
		n = toupper(ch) - 'A' + 1;
	}
	else
	{
		n = -1;
	}
	
	return n;
}
