//¡¶C Primer Plus¡·p175 6.16.8
#include <stdio.h>

int main(void)
{
	float a, b;
	
	while (scanf("%f %f", &a, &b) == 2)
	{
		printf("%f\n", (a - b) / (a * b));
	}
	printf("bye!");
	
	return 0;
 } 
