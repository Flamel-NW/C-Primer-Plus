//��C Primer Plus��p215 7.12.3
#include <stdio.h>
#define STOP 0

int main(void)
{
	int nums[20];
	int n_odd = 0;
	int n_even = 0;
	int sum_odd = 0;
	int sum_even = 0;
	int i = 0;
	
	scanf("%d", &nums[i]);
	
	while (nums[i] != STOP)
	{
		if (nums[i] % 2)	//�о��Լ��е�Сţ�� 
		{
			n_odd++;
			sum_odd += nums[i];
		}
		else
		{
			n_even++;
			sum_even += nums[i];
		}
		i++;
		scanf("%d", &nums[i]);
	}
	printf("�����ĸ���Ϊ��%d\n", n_odd);
	printf("������ƽ����Ϊ��%d\n", sum_odd / n_odd);
	
	printf("ż���ĸ���Ϊ��%d\n", n_even);
	printf("ż����ƽ����Ϊ��%d\n", sum_even / n_even);
	
	return 0;
}
