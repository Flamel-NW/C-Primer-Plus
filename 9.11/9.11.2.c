//¡¶C Primer Plus¡·p276 9.11.2
#include <stdio.h>

void chline(char ch,int i,int j);
int main(void)
{
	char ch;
	int a;
	int b;
	
	scanf("%c", &ch);
	scanf("%d%d", &a, &b);
	
	chline (ch, a, b);
	
	return 0;
}

void chline(char ch, int i, int j)
{
	int row;
	int line;
	
	for (row = 1; row <= j; row++)
	{
		for (line = 1; line <= i; line++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}
