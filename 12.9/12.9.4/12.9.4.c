//¡¶C Primer Plus¡·p410 12.9.4
#include <stdio.h>
#define TIMES 5

static int times = 0;
int function(void); 
int main(void)
{
	int n;
	
	int i;
	for (i = 0; i < TIMES; i++)
	{
		n = function();
	}
	printf("%d", n);
	
	return 0;
}

int function(void)
{
	return ++times;
}
