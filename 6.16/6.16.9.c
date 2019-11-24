//¡¶C Primer Plus¡·p175 6.16.9
#include <stdio.h>

float function(float x, float y);
int main(void)
{
	float a, b;
	
	while (scanf("%f %f", &a, &b) == 2)
	{
		printf("%f\n", function(a, b));
	}
	printf("bye!");
	
	return 0;
 } 
 
 float function(float x, float y)
 {
 	return (x - y) / (x * y);
 }
