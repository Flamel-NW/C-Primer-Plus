//《C Primer Plus》p215 7.12.10
#include <stdio.h>
#define TAXRATE1 0.15
#define TAXRATE2 0.28

int main(void)
{
	int option;
	int stage;
	
	while (1)
	{	
		int i;
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//打印分割线
		
		printf("\n\n请输入您应当缴纳税金的种类：\n");
		printf("1) 单身                          2) 户主\n");
		printf("2) 已婚，共有                    3) 已婚，离异\n");
		printf("5) 退出\n\n");
		
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//打印分割线
		printf("\n");
		
		scanf("%d", &option); 
		switch (option)
		{
			case 1:
				stage = 17850;
				break;
			case 2:
				stage = 23900;
				break;
			case 3:
				stage = 29750;
				break;
			case 4:
				stage = 14875;
				break;
			case 5:
				printf("再见!\n");
				break;
			default:
				printf("请输入正确的选项。\n");
				continue;
		}
		if (5 == option)
		{
			break;
		}
	
	
	float wage;
	float taxes;
	
	printf("请输入您的工资："); 
	scanf("%f", &wage);
	
	if (wage > stage)
	{
		taxes = (wage - stage) * TAXRATE2 + stage * TAXRATE1;
	}
	else
	{
		taxes = wage * TAXRATE1;
	}
	printf("您应缴纳的税金为：%.2f\n", taxes);
	}
	
	return 0;
 } 
