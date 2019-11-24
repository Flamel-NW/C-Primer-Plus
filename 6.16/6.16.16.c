//¡¶C Primer Plus¡·p176 6.16.16
#include <stdio.h>
#define PRINCIPAL 100

int main(void)
{
	float Daphne = PRINCIPAL;
	float Deirdre = PRINCIPAL;
	int year;
	
	for (year = 1; Daphne >= Deirdre; year++)
	{
		Daphne += PRINCIPAL * 0.1;
		Deirdre *= 1 + 0.05;
	}
	printf("%d", year);
	
	return 0;
 } 
