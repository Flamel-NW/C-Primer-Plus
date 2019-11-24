//¡¶C Primer Plus¡·p276 9.11.8 
#include <stdio.h>

double power(double n, int p);
int main(void)
{
	double x;
	double xpow;
	int exp;
	
	scanf("%lf%d", &x, &exp);
	xpow = power(x, exp);
	
	printf("%.2f", xpow);
	
	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	int i;
	
	if (p > 0)
	{
		for (i = 1; i <= p; i++)
		{
			pow *= n;
		}
	}
	if (p < 0)
	{
		for (i = 1; i <= -p; i++)
		{
			pow /= n;
		}
	}
	if (n == 0 && p == 0)
	{
		printf("Math error!\n");
	}
	
	return pow;
}
