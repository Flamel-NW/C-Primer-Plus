//¡¶C Primer Plus¡·p101 4.8.7
#include<stdio.h>
#include<float.h>

int main(void) 
{
	double a = 1.0 / 3.0;
	float b = 1.0 / 3.0;
	
	printf("%.6f %.6f\n%.12f %.12f\n%.16f %.16f\n", a, b ,a ,b ,a ,b);
	printf("%d %d", FLT_DIG, DBL_DIG);
	
	return 0; 
}
