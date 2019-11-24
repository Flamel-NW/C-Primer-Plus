//��C Primer Plus��p215 7.12.7
#include <stdio.h>
#define BASIC 10.00
#define OVERTIME 40
#define TAXRATE1 0.15
#define TAXRATE2 0.2
#define TAXRATE3 0.25

int main(void)
{
	int hours;
	float wage;
	float net_wage;
	float taxes = 0;
	
	printf("��������һ�ܹ�����Сʱ����");
	scanf("%d", &hours);
	
	if (hours > 40)
	{
		hours = 40 + (hours - 40) * 1.5;
	}
	
	wage = hours * BASIC;
	if (wage > 450)
	{
		taxes = (wage - 450) * TAXRATE3 + (450 - 300) * TAXRATE2 + 300 * TAXRATE1;
	}
	else if (wage > 300)
	{
		taxes = (wage - 300) * TAXRATE2 + 300 * TAXRATE1;
	}
	else 
	{
		taxes = wage * TAXRATE1;
	}
	
	net_wage = wage - taxes;
	
	printf("���Ĺ����ܶ�Ϊ��%.2f\n", wage);
	printf("˰��Ϊ��%.2f\n", taxes);
	printf("������Ϊ��%.2f\n", net_wage);
	
	return 0;
 } 
