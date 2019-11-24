//¡¶C Primer Plus¡·p175.6.16.5
#include <stdio.h>

int main(void)
{
	int row;
	char ch_max;
	char ch;
	int blank;
	int length;
	
	scanf("%c", &ch_max);
	
	const int ROWS = ch_max - 'A' + 1;
	
	for (row = 1; row <= ROWS; row++)
	{
		for (blank = 1; blank <= (ROWS - row); blank++)
		{
			printf(" ");
		}
		for (ch = 'A'; ch < ('A' + row); ch++)
		{
			printf("%c", ch);
		}
		ch -= 2;
		for (length = 1; length <= row - 1; length++, ch--)
		{
			printf("%c", ch);
		}
				
		printf("\n");
	 } 
	 
	 return 0;
 } 
