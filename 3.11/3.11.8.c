//¡¶C Primer Plus¡·p69 3.11.8
#include<stdio.h>

int main()
{
	float glass;
	scanf("%f", &glass);
	
	float pint = glass / 2;
	float ounce = glass * 8;
	float ladle = ounce * 2;
	float teaspoon = ladle * 3;
	
	printf("%f %f %f %f", pint, ounce, ladle, teaspoon);
	
	return 0;
 } 
