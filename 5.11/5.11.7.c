//��C Primer Plus��p134 5.11.7
#include <stdio.h>

void cube(double n);	//�Լ���д�ĵ�һ������ 
int main()
{
	double a;
	
	printf("������һ������"); 
	scanf("%lf", &a);
	
	cube(a);
	
	return 0; 
 }

void cube(double n)
{
	printf("���������ǣ�%f", n * n * n);
 } 
 
/*��C Primer Plus��p94 ��4.7 "%lf"�����Ѷ�Ӧ��ֵ����Ϊdouble���� 
	double��float�ڴ�ӡ�Ƕ�����ʹ��ת��˵��"%f"�����������ʱ�����ֱ�ʹ��"%lf"��"%f"  */

//�һ���û��ѧ����ô���Գ��� 
