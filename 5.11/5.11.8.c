//��C Primer Plus��p134 5.11.8 
#include <stdio.h>

int main()
{
	int first_operand;  //��Ըȡһ�����ı�����Ҳ��Ҫȡһ�����˲�֪����ʲô�ı����� 
	int second_operand;
	
	printf("This program computes moduli.\n"
			"Enter an interger to serve as the second operand:");
	scanf("%d", &second_operand);
	
	printf("Now enter the first operand:");
	scanf("%d", &first_operand);
	
	while (first_operand > 0)	//�ƺ���һ�½�������θĽ���һ�� 
	{
		printf("%d %% %d = %d\n",		//printf�����д�ӡһ��"%"��Ҫд��"%%" ��cpp p81 ��4.3�� 
				first_operand, second_operand, first_operand % second_operand);
		
		printf("Enter next number for first operand (<= 0 to quit):");
		scanf("%d", &first_operand);
	}
	printf("Done") ;
	
	return 0;
}

//���������߳����ֳ�do whileѭ������Ҫ�� 

//cpp p91 3.��ӡ�ϳ����ַ��� ����Ϊ����3��� 
