//¡¶C Primer Plus¡·p242 8.11.8
#include <stdio.h>

char get_choice(void);
char get_first(void);
float first_input(void);
float second_input(void);
void wrong_input(void);
float wrong_second_input(float a);
void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);

int main(void)
{
	int choice;
	float x;
	float y;
	
	while ((choice = get_choice()) != 'q')
	{
		x = first_input();
		y = second_input();
		
		switch (choice)
		{
			case 'a':
				add(x, y);
				break;
			case 's':
				subtract(x, y);
				break;
			case 'm':
				multiply(x, y);
				break;
			case 'd':
				y = wrong_second_input(y);
				divide(x, y);
				break;
			default:
				printf("Program error!\n");
		}
		while (getchar() != '\n')
		{
			continue;
		}
	}
	getchar();
	
	return 0;
}
 
char get_choice(void) 
{
	int ch;
	
	printf("Enter the operation of your choice:\n");
	printf("a. add				s. subtract\n");
	printf("m. multiply			d. divide\n");
	printf("q. quit\n");
	ch = get_first();
	while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
	{
		printf("Please respond with a, s, m, d, or q.\n");
		ch = get_first() ;
	}
	
	return ch;
}

char get_first(void)
{
	int ch;
	
	ch = getchar();
	while (getchar() != '\n')
	{
		continue;
	}
	
	return ch;
}

float first_input(void)
{
	float a;
	
	printf("Enter first number:");
	while (!scanf("%f", &a))
	{
		wrong_input();
	}
	
	return a;
}

float second_input(void)
{
	float b;
	
	printf("Enter second number:");
	while (!scanf("%f", &b))
	{
		wrong_input();
	}
	
	return b;
}

void add(float a, float b)
{
	printf("%.2f + %.2f = %.2f\n\n", a, b, a + b);
}
void subtract(float a, float b)
{
	printf("%.2f - %.2f = %.2f\n\n", a, b, a - b);
}
void multiply(float a, float b)
{
	printf("%.2f * %.2f = %.2f\n\n", a, b, a * b);
}
void divide(float a, float b)
{
	b = wrong_second_input(b);
	printf("%.2f / %.2f = %.2f\n\n", a, b, a / b);
}

void wrong_input(void)
{
	int ch;
	
	while ((ch = getchar()) != '\n')
	{
		putchar(ch);
	}
	
	printf(" is not an number.\n");
	printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
}

float wrong_second_input(float a)
{
	while (!a)
	{
		printf("Enter an number other than 0:");
		while (!scanf("%f", &a))
		{
			wrong_input();
		}
	}
	
	return a;
}
