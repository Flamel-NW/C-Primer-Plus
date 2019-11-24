//¡¶C Primer Plus¡·p276 9.11.9 
#include <stdio.h>

double power(double n, int p);
int main(void)
{
	double x;
	double xpow;
	int exp;
	
	scanf("%lf%d", &x, &exp);
	if (x == 0 && exp == 0)
	{
		printf("Math error!\n");
	}
	xpow = power(x, exp);
	
	printf("%.2f", xpow);
	
	return 0;
}

double power(double n, int p)
{
	double pow = 1;
	
	if (p > 0)
	{
		pow = power(n, (p - 1)) * n;
	}
	if (p < 0)
	{
		pow = power(n, (p + 1)) / n;
	}
	
	return pow;
}
