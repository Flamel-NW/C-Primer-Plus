//��C Primer Plus��p241 8.11.1
#include <stdio.h>

int main(void)
{
	int ch;
	int n_ch = 0;
	
	while ((ch = getchar()) != EOF)
	{
		n_ch++;
	}
	printf("�ַ���Ϊ��%d", n_ch);
	
	return 0;
 } 
