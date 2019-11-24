//¡¶C Primer Plus¡·p134 5.11.4
#include<stdio.h>
#define CM_PER_INCH 2.54
#define INCH_PER_FEET 12

int main()
{
	float height;
	int feet;
	float inch1, inch2;
	
	printf("Enter a height in centimeters:");
	scanf("%f", &height);
	
	while(height > 0)
	{
		inch1 = height / CM_PER_INCH;
		feet = (int) inch1 / INCH_PER_FEET;
		inch2 = inch1 - feet * INCH_PER_FEET;
		
		printf("%.1f cm = %d feet, %.1f inches\n", height, feet, inch2);
		
		printf("Enter a height in centimeters (<=0 to quit):");
		scanf("%f", &height);
	}
	printf("bye!");
	
	return 0;
}

