//��C Primer Plus��p100 4.8.2
#include<stdio.h>
#include<string.h>

int main(void)
{
	char Name[40];
	int Name_length;
	
	printf("�������������֣�");
	scanf("%s", Name);
	Name_length = strlen(Name);
	
	printf("\"%s\"\n", Name);
	printf("\"%20s\"\n", Name);
	printf("\"%-20s\"\n", Name);
	printf("\"%*s\"\n", Name_length + 3, Name);
	
	return 0; 
 } 
 
// strlen()������Ҫ����string.hͷ�ļ� 
