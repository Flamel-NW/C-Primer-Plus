//¡¶C Primer Plus¡·p372 11.13.8
#include <stdio.h>
#define INSIZE 5
#define OUTSIZE 15

char * string_in(char outside[], char inside[]);
int main(void)
{
	char out[OUTSIZE] = "I have an pen.";
	char in[INSIZE] = "heve";
	
	if (string_in(out, in))
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No!\n");
	}
	
	return 0;
}

char * string_in(char outside[], char inside[])
{
	int i, j;
	char * re = NULL;
	
	for (i = 0, j = 0; outside[i]; i++)
	{
		if (outside[i] == inside[j])
		{
			if (inside[j])
			{
				j++;
			}
		}
		if (!inside[j])
		{
			re = inside;
			break;
		}
	}
	
	return re;
}
