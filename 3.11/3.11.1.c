//¡¶C Primer Plus¡·p68 3.11.1
#include<stdio.h> 
int main()
{
	int i = 2147483647;
	unsigned int j = 4294967295;
	
	printf("%d %d %d\n", i, i+1, i+2);
	printf("%u %u %u\n", j, j+1, j+2);
	
	float toobig = 3.4E38 * 100.0f;
	printf("%e\n", toobig); 
	
	float toosmall = 0.1234E-38 / 10;
	printf ("%e\n", toosmall);
	
	return 0;
}
