//��C Primer Plus��p242 8.11.4 
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	int ch;
	int n_ch = 0;
	int n_words = 0; 
	bool inword = false;
	
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			n_ch++;
		}
		
		if (!isblank(ch) && !inword)
		{
			n_words++;
			inword = true;
		}
		if (isblank(ch) && inword)
		{
			inword = false;
		}
	}
	float ch_per_word = (float)n_ch / (float)n_words;
	printf("ƽ��ÿ��������%.2f����ĸ", ch_per_word);
	
	return 0;
 } 
 
//��һ�����ʹ�����ֲ��ԣ�һ��ͨ������һ��bool����inword��ʵ�֣���һ�������ͬʱ���浱ǰ�ַ�ch����һ�ַ�pre_ch��ʵ�� 
