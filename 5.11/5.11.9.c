//《C Primer Plus》p134 5.11.9
#include <stdio.h>

void Temperatures(double temperature);
int main()
{
	double Fahrenheit;
	
	printf("Enter a temperature in Fahrenheit:");
	
	while (scanf("%lf", &Fahrenheit) == 1)
	{
		Temperatures(Fahrenheit);
		printf("Enter a temperature in Fahrenheit (q to quit):");
	}
	printf("Done");
	
	return 0;
}

void Temperatures(double temperature)
{
	const float ABSOLUTE_ZERO = 273.16;
	
	double centigrade = 5.0 / 9.0 * (temperature - 32.0);
	double kelvin = centigrade + ABSOLUTE_ZERO;
	
	printf("%.2f °F = %.2f °C = %.2f K\n", temperature, centigrade, kelvin);
}

//这一题要考虑作用域？？是我想多了还是有点超纲？ 
