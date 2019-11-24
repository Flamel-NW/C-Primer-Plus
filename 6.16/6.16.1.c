//《C Primer Plus》p174 6.16.1 
#include<stdio.h>

int main()
{
	char alphabet[26];
	int index;
	
	/*	我写的： 
	for (index = 0, alphabet[0] = 'a'; index < 26; index++) 
	{
		alphabet[index + 1] = alphabet[index] + 1;
	}	*/
	
//	下面是csdn答案上写的 
	for (index = 1, alphabet[0] = 'a'; index < 26; index++)
	{
		alphabet[index] = 'a' + index;
	}
//	似乎此种方法更优 
	
	for (index = 0; index < 26; index++)
	{
		printf("%c ", alphabet[index]);
	}
	
	return 0;
}

//index的作用不可替代 
