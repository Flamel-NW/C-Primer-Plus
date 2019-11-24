//《C Primer Plus》p242 8.11.4 
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
	printf("平均每个单词有%.2f个字母", ch_per_word);
	
	return 0;
 } 
 
//这一题可以使用两种策略，一种通过设置一个bool变量inword来实现；另一种则可以同时保存当前字符ch和上一字符pre_ch来实现 
