//¡¶C Primer Plus¡·p175 6.16.13
#include <stdio.h>

int main(void)
{
	int power[8];
	int p;
	int i;
	
	for (p = 0; p < 8; p++)
	{
		power[p] = 1;
		for (i = 0; i <= p; i++)
		{
			power[p] *= 2;
		}
	}
	p = 0;
	
	do
	{
		printf("%d ", power[p]);
		p++;
	} while (p < 8);
	
	return 0;
 } 
 
// do whileÓï¾äÄ©Î²ÒªÇó; 
