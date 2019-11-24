//¡¶C Primer Plus¡·p518 15.9.3
#include <stdio.h>
#include <limits.h>

int open_bit(int n);
int main(void)
{
	int a = 79;
	printf("%d", open_bit(a));
	
	return 0;
}

int open_bit(int n)
{
	int ret = 0;
	size_t size = sizeof(int) * CHAR_BIT;
	
	int i;
	for (i = 0; i < size; i++)
	{
		if (n & 0x1 == 1)
		{
			ret++;
		}
		n >>= 1;
	}
	
	return ret;
}
