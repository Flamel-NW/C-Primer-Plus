//��C Primer Plus��p174 6.16.1 
#include<stdio.h>

int main()
{
	char alphabet[26];
	int index;
	
	/*	��д�ģ� 
	for (index = 0, alphabet[0] = 'a'; index < 26; index++) 
	{
		alphabet[index + 1] = alphabet[index] + 1;
	}	*/
	
//	������csdn����д�� 
	for (index = 1, alphabet[0] = 'a'; index < 26; index++)
	{
		alphabet[index] = 'a' + index;
	}
//	�ƺ����ַ������� 
	
	for (index = 0; index < 26; index++)
	{
		printf("%c ", alphabet[index]);
	}
	
	return 0;
}

//index�����ò������ 
