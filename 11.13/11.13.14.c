//¡¶C Primer Plus¡·p372 11.13.14
#include <stdio.h>
#include <stdlib.h> //°üº¬atof()ºÍatoi() 

int main(int argc, char * argv [])
{
	double x = atof(argv[1]);
	int n = atoi(argv[2]);
	
	double result = 1.0;
	
	int i;
	for (i = 0; i < n; i++)
	{
		result *= x;
	}
	
	printf("%.2f", result);
	
	return 0;
}
