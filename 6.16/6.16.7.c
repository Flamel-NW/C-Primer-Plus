//��C Primer Plus��p175 6.16.7
#include <stdio.h>
#include <string.h>

int main(void)
{
	char ch[20];
	int i;
	
	scanf("%s", ch);
	
	for (i = strlen(ch) - 1; i >= 0; i--)
	{
		printf("%c", ch[i]);
	}
	
	return 0;
 } 
 
/* �����˵Ҫ���õ���¼��һ���ַ����飬���������Ѿ�����һ���ַ����������Ե�12�в�Ҫ��һ���������ַ���ĩβ�Ŀ��ַ�\0
 	����ȷӦ����ô���أ�����getchar()�𣿣�  */ 
