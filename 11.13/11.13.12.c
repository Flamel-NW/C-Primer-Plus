//¡¶C Primer Plus¡·p372 11.13.12
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define SIZE 50

int n_words(char string[]);
int n_uppers(char string[]);
int n_lowers(char string[]);
int n_puncts(char string[]);
int n_digits(char string[]);
int main(void)
{
	char string[SIZE];
	fgets(string, SIZE, stdin);
	
	printf("%d %d %d %d %d"
			, n_words(string)
			, n_uppers(string)
			, n_lowers(string)
			, n_puncts(string)
			, n_digits(string));
	
	return 0;
}

int n_words(char string[])
{
	int num = 0;
	bool inword = false;
	int i;
	
	for (i = 0; string[i]; i++)
	{
		if (!isblank(string[i]) && !inword)
		{
			num++;
			inword = true;
		}
		if (isblank(string[i]) && inword)
		{
			inword = false;
		}
	}
	
	return num;
}

int n_uppers(char string[])
{
	int num = 0;
	
	int i;
	for (i = 0; string[i]; i++)
	{
		if(isupper(string[i]))
		{
			num++;
		}
	}
	
	return num;
}

int n_lowers(char string[])
{
	int num = 0;
	
	int i;
	for (i = 0; string[i]; i++)
	{
		if(islower(string[i]))
		{
			num++;
		}
	}
	
	return num;
}

int n_puncts(char string[])
{
	int num = 0;
	
	int i;
	for (i = 0; string[i]; i++)
	{
		if(ispunct(string[i]))
		{
			num++;
		}
	}
	
	return num;
}

int n_digits(char string[])
{
	int num = 0;
	
	int i;
	for (i = 0; string[i]; i++)
	{
		if(isdigit(string[i]))
		{
			num++;
		}
	}
	
	return num;
}
