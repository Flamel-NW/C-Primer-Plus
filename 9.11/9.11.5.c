//¡¶C Primer Plus¡·p276 9.11.5
#include <stdio.h>

void large_of(double * x, double * y);
int main(void)
{
	double a;
	double b;
	
	scanf("%lf%lf", &a, &b);
	
	large_of(&a, &b);
	
	printf("%.2f, %.2f", a, b);
	
	return 0;
 } 

void large_of(double * x, double * y)
{
	if (*x > *y)
	{
		*y = *x;
	}
	else
	{
		*x = *y;
	}
}
