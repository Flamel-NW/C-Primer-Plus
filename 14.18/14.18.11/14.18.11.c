//¡¶C Primer Plus¡·p492 14.18.11
#include <stdio.h>
#include <math.h>
#define SIZE 10

void transform(double nums1[], double nums2[], int num, double (* ptr)(double));
double sqr(double n);
double twice(double b);

int main(void)
{
	double source[SIZE];
	double target[SIZE];
	
	int i;
	for (i = 0; i < SIZE; i++)
	{
		source[i] = (float) i;
	}
	
	transform(source, target, SIZE, sin);
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", target[i]);
	}
	putchar('\n');
	
	transform(source, target, SIZE, cos);
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", target[i]);
	}
	putchar('\n');
	
	transform(source, target, SIZE, sqr);
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", target[i]);
	}
	putchar('\n');
	
	transform(source, target, SIZE, twice);
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", target[i]);
	}
	putchar('\n');
	
	return 0;
}

double sqr(double n)
{
	return (n * n);
}

double twice(double n)
{
	return (2 * n);
}

void transform(double nums1[], double nums2[], int num, double (* ptr)(double))
{
	int i;
	for (i = 0; i < num; i++)
	{
		nums2[i] = ptr(nums1[i]);
	}
}
