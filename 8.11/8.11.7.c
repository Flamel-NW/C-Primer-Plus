//《C Primer Plus》p215 8.11.7
#include <stdio.h>
#define OVERTIME 40
#define TAXRATE1 0.15
#define TAXRATE2 0.2
#define TAXRATE3 0.25

int main(void)
{
	int hours;
	float basic;
	float wage;
	float net_wage;
	float taxes = 0;
	char option;
	
	while (1)
	{	
		int i;
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//打印分割线
		
		printf("\n\nEnter the number corresponding to the desired pay rate or action:\n");
		printf("a) $8.75//hr                          b) $9.33//hr\n");
		printf("c) $10.00//hr                         d) $11.20//hr\n");
		printf("q) quit\n\n");
		
			for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//打印分割线
		printf("\n");
		option = getchar();
		switch (option)
		{
			case 'a':
				basic = 8.75;
				break;
			case 'b':
				basic = 9.33;
				break;
			case 'c':
				basic = 10.00;
				break;
			case 'd':
				basic = 11.20;
				break;
			case 'q':
				printf("Bye!\n");
				break;
			default:
				printf("Please enter the correct number.\n");
				continue;
		}
		if ('q' == option)
		{
			break;
		}
	
		printf("请输入您一周工作的小时数：");
		scanf("%d", &hours);
		
		if (hours > 40)
		{
			hours = 40 + (hours - 40) * 1.5;
		}
		
		wage = hours * basic;
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
		
		printf("您的工资总额为：%.2f\n", wage);
		printf("税金为：%.2f\n", taxes);
		printf("净收入为：%.2f\n", net_wage);
		while (getchar() != '\n')
		{
			continue;
		}
	}
	
	return 0;
 } 
