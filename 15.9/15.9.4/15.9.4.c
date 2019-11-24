//¡¶C Primer Plus¡·p518 15.9.4
#include <stdio.h>
#include <stdbool.h>

bool isopen(int n, int i);
int main(void)
{
	int a = 79; // 1001111
	int b = 4;
	
	if (isopen(a, b))
	{
		puts("Open!");
	}
	else
	{
		puts("Closed!");
	}
	
	return 0;
}

bool isopen(int n, int i)
{
	bool ret;
	
	n >>= i - 1;
	ret = (n & 0x1 == 1) ? true : false;
	
	return ret;
}
