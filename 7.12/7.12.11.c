//��C Primer Plus��p216 7.12.11
#include <stdio.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09
#define DISCOUNT 0.05

int main(void)
{
	float w_artichoke = 0;
	float w_beet = 0;
	float w_carrot = 0;

	char option;
	while (1)
	{
		float add = 0;
		int i;
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//��ӡ�ָ���
		
		printf("\n\n��������Ҫ�������߲˼�������\n");
		printf("a. ��                          b. ���\n");
		printf("c. ���ܲ�                        q. �˳�����\n");
		
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//��ӡ�ָ���
		printf("\n");
		
		scanf("%c", &option);
		getchar();
		switch (option)
		{
			case 'a':
				printf("��������Ҫ�������󼻵İ�����");
				scanf("%f", &add);
				w_artichoke += add;
				break;
			case 'b':
				printf("��������Ҫ��������˵İ�����");
				scanf("%f", &add);
				w_beet += add;
				break;
			case 'c':
				printf("��������Ҫ�����ĺ��ܲ��İ�����");
				scanf("%f", &add);
				w_carrot += add;
				break;
			case 'q':
				break;
			default:
				printf("��������ȷ��ѡ�\n");
				continue;
		}
		if ('q' == option)
		{
			break;
		}
		printf("�����ɹ���\n");
		printf("���Ѷ���%.2f������\n", w_artichoke);
		printf("���Ѷ���%.2f�������\n", w_beet);
		printf("���Ѷ���%.2f���ĺ��ܲ�\n", w_carrot);
		getchar();
	}
	
	float gross_price = w_artichoke * ARTICHOKE + w_beet * BEET + w_carrot * CARROT;
	float discount = 0;
	if (gross_price >= 100)
	{
		discount = gross_price * DISCOUNT;
	}
	float weight = w_artichoke + w_beet + w_carrot;
	float freight = 0;
	if (weight <= 5)
	{
		freight = 6.5;
	}
	else if (weight <= 20)
	{
		freight = 14;
	}
	else
	{
		freight = 14 + (freight - 20) * 0.5; 
	}
	
	printf("�����ܼ�Ϊ%.2f$\n", gross_price);
	printf("�ۿ�Ϊ%.2f$\n", discount);
	printf("�˷ѺͰ�װ��Ϊ%.2f$\n", freight);
	printf("������ɣ�\n\n");
	
	float net_price = gross_price - discount + freight;
	printf("���ι�����Ϣ��\n");
	printf("��Ʒ  		����			���\n");
	printf("��		%.2f$/��		%.2f$\n", ARTICHOKE, w_artichoke * ARTICHOKE);
	printf("���		%.2f$/��		%.2f$\n", BEET, w_beet * BEET);
	printf("���ܲ�		%.2f$/��		%.2f$\n", CARROT, w_carrot * CARROT);
	printf("�������ܷ��ã�%.2f$\n", gross_price);
	printf("�ۿۣ�%.2f$\n", discount);
	printf("�˷ѺͰ�װ�ѣ�%.2f$\n", freight);
	printf("�����ܶ%.2f$\n", net_price);
	
	getchar(); 		//��ֹ�������ˣ�dev���治����ǵ������е�ʱ��ᣩ 
	
	return 0;
}

//Ҫ�����ʶ35��67�е�getchar()�ֶ�ô��Ҫ 
