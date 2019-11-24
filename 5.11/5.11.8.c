//《C Primer Plus》p134 5.11.8 
#include <stdio.h>

int main()
{
	int first_operand;  //宁愿取一个长的变量名也不要取一个让人不知道是什么的变量名 
	int second_operand;
	
	printf("This program computes moduli.\n"
			"Enter an interger to serve as the second operand:");
	scanf("%d", &second_operand);
	
	printf("Now enter the first operand:");
	scanf("%d", &first_operand);
	
	while (first_operand > 0)	//似乎下一章讲到了如何改进这一行 
	{
		printf("%d %% %d = %d\n",		//printf函数中打印一个"%"需要写成"%%" （cpp p81 表4.3） 
				first_operand, second_operand, first_operand % second_operand);
		
		printf("Enter next number for first operand (<= 0 to quit):");
		scanf("%d", &first_operand);
	}
	printf("Done") ;
	
	return 0;
}

//这个程序的冗长体现出do while循环的重要性 

//cpp p91 3.打印较长的字符串 我认为方法3最好 
