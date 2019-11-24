//《C Primer Plus》p134 5.11.7
#include <stdio.h>

void cube(double n);	//自己编写的第一个函数 
int main()
{
	double a;
	
	printf("请输入一个数："); 
	scanf("%lf", &a);
	
	cube(a);
	
	return 0; 
 }

void cube(double n)
{
	printf("它的立方是：%f", n * n * n);
 } 
 
/*《C Primer Plus》p94 表4.7 "%lf"表明把对应的值储存为double类型 
	double和float在打印是都可以使用转换说明"%f"，可在输入的时候必须分别使用"%lf"和"%f"  */

//我还是没有学会怎么调试程序 
