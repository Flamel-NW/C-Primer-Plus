//¡¶C Primer Plus¡·p241 8.11.2
#include <stdio.h>

int main(void)
{
	int ch;
	int n_ch = 0;
	
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
		switch (ch)
		{
			case (int)'\t':
				printf("\\t ");
				break;
			case (int)'\n':
				printf("\\n ");
				break;
			default:
				if (ch < (int)' ')
				{
					printf("-^%c ", ch + 64);
				}
				else
				{
					printf("-%d ", ch);
				}
		}
		n_ch++;
		if (n_ch >= 8)
		{
			printf("\n");
			n_ch = 0;
		}
	}
	
	return 0;
 } 
