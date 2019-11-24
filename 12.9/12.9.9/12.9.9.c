//¡¶C Primer Plus¡·p411 12.9.9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

char ** words(int n);
int main(void)
{
	int n_words;
//	int length;
//	char temp[SIZE];
	char ** st;
	
	printf("How many words do you wish to enter? ");
	scanf("%d", &n_words);
	
	printf("Enter %d words now:\n", n_words);
	st = words(n_words);
	
	int i;
//	for (i = 0; i < n_words; i++)
//	{
//		scanf("%s", temp);
//		length = strlen(temp) + 1;
//		st[i] = (char *) malloc(length * sizeof(char));
//		strcpy(st[i], temp);
//	}
	
	printf("Here are your words:\n");
	for (i = 0; i < n_words; i++)
	{
		fputs(st[i], stdout);
		printf("\n");
		free(st[i]);
	}
	free(st);
	
	return 0;
}

char ** words(int n)
{
	char temp[SIZE];
	int length;
	
	char ** st;
	st = (char **) malloc(n * sizeof(char *));
	
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", temp);
		length = strlen(temp) + 1;
		st[i] = (char *) malloc(length * sizeof(char));
		strcpy(st[i], temp);
	}
	
	return st;
} 
