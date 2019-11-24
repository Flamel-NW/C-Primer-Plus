//¡¶C Primer Plus¡·p491 14.18.10
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void print_a(void);
void print_b(void);
void print_c(void);
void print_d(void);

int main(void)
{
	char ch;
	void (* ptrs[SIZE])(void);
	ptrs[0] = print_a;
	ptrs[1] = print_b;
	ptrs[2] = print_c;
	ptrs[3] = print_d;
	
	puts("MENU");
	puts("a)		b)");
	puts("c)		d)");
	
	ch = getchar();
	while (getchar() != '\n')
	{
		continue;
	}
	
	switch (ch)
	{
		case 'a':
			ptrs[0]();
			break;
		case 'b':
			ptrs[1]();
			break;
		case 'c':
			ptrs[2]();
		case 'd':
			ptrs[3]();
		default:
			exit(EXIT_FAILURE);
	}
	
	return 0;
}

void print_a(void)
{
	putchar('a');
}

void print_b(void)
{
	putchar('b');
}
void print_c(void)
{
	putchar('c');
}
void print_d(void)
{
	putchar('d');
}
