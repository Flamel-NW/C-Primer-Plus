//°∂C Primer Plus°∑p409 12.9.2
//pe12-2b.c
//”Îpe12-2a.c“ª∆±‡“Î 
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
	int mode;
	
	printf("Enter 0 for metric mode, 1 for US mode:");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		set_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode, 1 for US mode:");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	
	return 0;
}


