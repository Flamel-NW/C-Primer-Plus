//¡¶C Primer Plus¡·p563 16.18.2
#include <stdio.h>
#define HARMONIC(X, Y) (2 / ((1 / X) + (1 / Y)))

int main(void)
{
	double a = 2;
	double b = 3;
	printf("%.2f", HARMONIC(a, b));
	
	return 0;
}
