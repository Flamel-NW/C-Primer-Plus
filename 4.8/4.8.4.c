//《C Primer Plus》p101 4.8.4
#include<stdio.h>

int main(void)
{
	float height;
	printf("请输入你的身高："); 
	scanf("%f", &height);
	
	printf("Dabney, you are %.3f meters tall", height / 100);
	
	return 0; 
 } 
