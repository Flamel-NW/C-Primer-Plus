//¡¶C Primer Plus¡·p437 13.11.9
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int n_words = 0;
int main(void)
{
	extern int n_words;
	FILE * fp;
	char words[MAX];
	
	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stderr, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%s\n", words);
	}
	
	puts("File contents:");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
	{
		printf("%d ", ++n_words);
		puts(words);
	}
	puts("Done!");
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing file.\n");
	}
	
	return 0;
}
