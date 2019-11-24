//¡¶C Primer Plus¡·p372 11.13.13 
#include <stdio.h>

int main(int argc, char * argv [])
{
	int i;
	
	for (i = 1; i < argc; i++)
	{
		printf("%s ", argv[argc - i]);
	}
	printf("\n");
	
	return 0;
}
