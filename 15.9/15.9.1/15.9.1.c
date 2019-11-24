//¡¶C Primer Plus¡·p518 15.9.1
#include <stdio.h>
#include <string.h>

int bstoi(char bs[]);

int main(void)
{
	char pbin[] = "01001001";
	printf("%d", bstoi(pbin));
	
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
