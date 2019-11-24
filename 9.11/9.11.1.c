//¡¶C Primer Plus¡·p276 9.11.1
#include <stdio.h>

double min(double x, double y);
int main(void)
{
	double a;
	double b;
	
	scanf("%lf%lf", &a, &b);
	
	printf("%.2f", min(a, b));
	
	return 0;
 } 
 
double min(double x, double y)
{
	return ((x > y) ? y : x);
}
