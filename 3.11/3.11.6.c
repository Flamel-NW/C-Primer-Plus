 //¡¶C Primer Plus¡·p69 3.11.6 
#include<stdio.h>

int main()
{
	float quart;
	scanf("%f", &quart);
	
	float gram = quart / 3E-23;
	printf("%e", gram);
	
	return 0;
} 
