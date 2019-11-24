//¡¶C Primer Plus¡·p176 6.16.15
#include <stdio.h>
#include <string.h> 

int main(void)
{
	char ch[255];
	int i;
	
	scanf("%s", ch);
	
	for (i = strlen(ch) - 1; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}
	
	return 0;
 } 
