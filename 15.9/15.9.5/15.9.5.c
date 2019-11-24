//¡¶C Primer Plus¡·p518 15.9.5
#include <stdio.h>
#include <limits.h>

void rotate_l(unsigned int * m, int n);
int main(void)
{
	unsigned int a = 1;
	a <<= 31;
	rotate_l(&a, 5);
	printf("%u", a);
	
	return 0;
}

void rotate_l(unsigned int * m, int n)
{
	size_t size = sizeof(unsigned int) * CHAR_BIT;
	
	unsigned int mask = 1;
	unsigned int a;
	mask <<= size - 1;
	
	int i;
	for (i = 0; i < n; i++)
	{
		a = *m & mask;
		a >>= size - 1;
		*m <<= 1;
		*m |= a;
	}
}
