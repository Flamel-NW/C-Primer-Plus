//¡¶C Primer Plus¡·p276 9.11.10
#include <stdio.h>

void to_base_n(int x, int n);
int main(void)
{
	int number;
	int n;
	
	scanf("%d%d", &number, &n);
	to_base_n(number, n);
	
	return 0;
}

void to_base_n(int x, int n)
{
	int r;
	
	r = x % n;
	if (x >= n)
	{
		to_base_n(x / n, n);
	}
	char ch_r = r + ('0' - 0);
	putchar(ch_r);
}
