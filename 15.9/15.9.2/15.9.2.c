//¡¶C Primer Plus¡·p518 15.9.2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int bstoi(char bs[]);
char * itobs(int n, char ps[]);

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int a, b;
	char str[CHAR_BIT + 1];
	
	a = bstoi(argv[1]);
	b = bstoi(argv[2]);
	
	printf("%s\n", itobs((~a), str));
	printf("%s\n", itobs((~b), str));
	printf("%s\n", itobs((a & b), str));
	printf("%s\n", itobs((a | b), str));
	printf("%s\n", itobs((a ^ b), str));
	
	return 0;
}

int bstoi(char bs[])
{
	int ret = 0;
	size_t size = strlen(bs);
	
	int i;
	for (i = 0; i < size; i++)
	{
		ret = (ret << 1) + (bs[i] - '0');
	}
	
	return ret;
}
 
char * itobs(int n, char ps[])
{
	int i;
	
	for (i = CHAR_BIT - 1; i >= 0; i--, n >>= 1)
	{
		ps[i] = (01 & n) + '0';
	}
	ps[CHAR_BIT] = '\0';
	
	return ps;
}
