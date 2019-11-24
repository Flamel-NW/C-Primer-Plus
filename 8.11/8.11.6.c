//¡¶C Primer Plus¡·p242 8.11.6
#include <stdio.h>
#include <ctype.h>

char get_first(void);
int main(void)
{
	int c;
	
	while ((c = get_first()) != EOF)
	{
		putchar(c);
	}
	
	return 0;
 }		 
 
char get_first(void)
{
	int ch;
	
	while (isblank(ch = getchar()))
	{
		continue;
	}
	while (getchar() != '\n')
	{
		continue;
	}
	
	return ch;
}
