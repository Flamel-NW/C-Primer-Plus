//《C Primer Plus》p276 9.11.6
#include <stdio.h>

void sort(double * a, double * b, double * c);
int main(void)
{
	double x, y, z;
	
	scanf("%lf%lf%lf", &x, &y, &z);
	
	sort(&x, &y, &z);
	
	printf("%.2f %.2f %.2f", x, y, z);
	
	return 0;
}

void sort(double * a, double * b, double * c)
{
	double temp;
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *c;
		*c = *a;
		*a = temp;
	}	
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	 } //	似乎是经典的三数排序算法 
}
