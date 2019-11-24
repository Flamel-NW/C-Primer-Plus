//《C Primer Plus》p100 4.8.1
#include<stdio.h>

int main(void) 
{
	char FirstName[40];
	char LastName[40];
	
	printf("请输入您的姓："); 
	scanf("%s", LastName);
	printf("请输入您的名：");
	scanf("%s", FirstName);
	
	printf("%s,%s", FirstName, LastName);
	
	return 0; 
}
