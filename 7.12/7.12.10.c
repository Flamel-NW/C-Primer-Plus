//��C Primer Plus��p215 7.12.10
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
		}	//��ӡ�ָ���
		
		printf("\n\n��������Ӧ������˰������ࣺ\n");
		printf("1) ����                          2) ����\n");
		printf("2) �ѻ飬����                    3) �ѻ飬����\n");
		printf("5) �˳�\n\n");
		
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//��ӡ�ָ���
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
				printf("�ټ�!\n");
				break;
			default:
				printf("��������ȷ��ѡ�\n");
				continue;
		}
		if (5 == option)
		{
			break;
		}
	
	
	float wage;
	float taxes;
	
	printf("���������Ĺ��ʣ�"); 
	scanf("%f", &wage);
	
	if (wage > stage)
	{
		taxes = (wage - stage) * TAXRATE2 + stage * TAXRATE1;
	}
	else
	{
		taxes = wage * TAXRATE1;
	}
	printf("��Ӧ���ɵ�˰��Ϊ��%.2f\n", taxes);
	}
	
	return 0;
 } 
