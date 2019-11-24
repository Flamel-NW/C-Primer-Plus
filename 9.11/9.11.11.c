//¡¶C Primer Plus¡·p276 9.11.11
#include <stdio.h> 

unsigned long long Fibonacci(int n);
int main(void)
{
	int a;
	scanf("%d", &a);
	
	printf("%llu", Fibonacci(a));
	
	return 0;
}

unsigned long long Fibonacci(int n)
{
	unsigned long long f = 1;
	unsigned long long a = 1;
	unsigned long long b = 1;
	int i;
	
	if (n > 2)
	{
		for (i = 3; i <= n; i++)
		{
			f = a + b;
			b = a;
			a = f;
		}
	}
	
	return f;
}

 
