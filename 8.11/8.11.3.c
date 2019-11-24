//《C Primer Plus》p242 8.11.3
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int n_lower = 0;
	int n_upper = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
		{
			n_lower++;
		}
		else if (isupper(ch))
		{
			n_upper++;
		}
	}
	printf("小写字母有%d个\n", n_lower);
	printf("大写字母有%d个\n", n_upper);
	
	return 0;
 } 
