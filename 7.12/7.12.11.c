//《C Primer Plus》p216 7.12.11
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
		}	//打印分割线
		
		printf("\n\n请输入您要订购的蔬菜及磅数：\n");
		printf("a. 洋蓟                          b. 甜菜\n");
		printf("c. 胡萝卜                        q. 退出订购\n");
		
		for (i = 0; i < 65; i++)
		{
			printf("*");
		}	//打印分割线
		printf("\n");
		
		scanf("%c", &option);
		getchar();
		switch (option)
		{
			case 'a':
				printf("请输入您要订购的洋蓟的磅数：");
				scanf("%f", &add);
				w_artichoke += add;
				break;
			case 'b':
				printf("请输入您要订购的甜菜的磅数：");
				scanf("%f", &add);
				w_beet += add;
				break;
			case 'c':
				printf("请输入您要订购的胡萝卜的磅数：");
				scanf("%f", &add);
				w_carrot += add;
				break;
			case 'q':
				break;
			default:
				printf("请输入正确的选项。\n");
				continue;
		}
		if ('q' == option)
		{
			break;
		}
		printf("订购成功！\n");
		printf("您已订购%.2f磅的洋蓟\n", w_artichoke);
		printf("您已订购%.2f磅的甜菜\n", w_beet);
		printf("您已订购%.2f磅的胡萝卜\n", w_carrot);
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
	
	printf("货物总价为%.2f$\n", gross_price);
	printf("折扣为%.2f$\n", discount);
	printf("运费和包装费为%.2f$\n", freight);
	printf("订购完成！\n\n");
	
	float net_price = gross_price - discount + freight;
	printf("本次购买信息：\n");
	printf("商品  		单价			金额\n");
	printf("洋蓟		%.2f$/磅		%.2f$\n", ARTICHOKE, w_artichoke * ARTICHOKE);
	printf("甜菜		%.2f$/磅		%.2f$\n", BEET, w_beet * BEET);
	printf("胡萝卜		%.2f$/磅		%.2f$\n", CARROT, w_carrot * CARROT);
	printf("订单的总费用：%.2f$\n", gross_price);
	printf("折扣：%.2f$\n", discount);
	printf("运费和包装费：%.2f$\n", freight);
	printf("费用总额：%.2f$\n", net_price);
	
	getchar(); 		//防止程序闪退（dev里面不会可是单独运行的时候会） 
	
	return 0;
}

//要充分认识35和67行的getchar()又多么重要 
