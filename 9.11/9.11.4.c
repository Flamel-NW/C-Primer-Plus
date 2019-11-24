//¡¶C Primer Plus¡·p276 9.11.4
#include <stdio.h>

double harmonic_average(double a, double b);
int main(void)
{
	double x;
	double y;
	
	scanf("%lf%lf", &x, &y);
	
	printf("%.2f", harmonic_average(x, y));
	
	return 0;
 } 	
 
double harmonic_average(double a, double b)
{
	return 2 / ((1 / a) + (1 / b));
}
