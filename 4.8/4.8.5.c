//��C Primer Plus��p101 4.8.5
#include<stdio.h>

int main(void)
{
	float speed, file;
	
	printf("�����������ٶȣ�");
	scanf("%f", &speed);
	 
	printf("�������ļ���С��");
	scanf("%f", &file);
	
	printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed, file);
	printf("downloads in %.2f seconds", file * 8 / speed); 
	
	return 0; 
 } 
