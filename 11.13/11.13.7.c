//��C Primer Plus��p372 11.13.7
#include <stdio.h>
#define SIZE1 30 
#define SIZE2 15
#define COPY 12

char * mystrncpy(char string1[], char string2[], int n);
int main(void)
{
	char str1[SIZE1] = "I have a pan. I have an apple";
	char str2[SIZE2] = "I have a pen.";
	
	mystrncpy(str1, str2, COPY);
	fputs(str1, stdout);
	
	return 0;
}

char * mystrncpy(char string1[], char string2[], int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		string1[i] = string2[i];
	}
	
	return string1;
}

//ʵ��û�а취�����ν��Ŀ���ַ��������Կ��ַ���β������ 
