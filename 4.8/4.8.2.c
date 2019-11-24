//《C Primer Plus》p100 4.8.2
#include<stdio.h>
#include<string.h>

int main(void)
{
	char Name[40];
	int Name_length;
	
	printf("请输入您的名字：");
	scanf("%s", Name);
	Name_length = strlen(Name);
	
	printf("\"%s\"\n", Name);
	printf("\"%20s\"\n", Name);
	printf("\"%-20s\"\n", Name);
	printf("\"%*s\"\n", Name_length + 3, Name);
	
	return 0; 
 } 
 
// strlen()函数需要引入string.h头文件 
