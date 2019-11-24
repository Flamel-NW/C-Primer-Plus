//《C Primer Plus》p438 13.11.12
#include <stdio.h>
#include <stdlib.h>
#define NAME 20
#define ROWS 20
#define COLS 30

int main(void)
{
	FILE * f_n, * f_p;
	char name_n[NAME] = "numbers.txt";
	char name_p[NAME] = "picture.txt";
	int numbers[ROWS][COLS];
	char chs[] = " .':~*=&%#";		//将数字转换为字符，用switch大为繁琐，看了答案觉得很强
	char picture[ROWS][COLS + 1];
	
	if ((f_n = fopen(name_n, "r")) == NULL)
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", name_n);
		exit(EXIT_FAILURE);
	}
	if ((f_p = fopen(name_p, "w")) == NULL)
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", name_p);
		exit(EXIT_FAILURE);
	}
	
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			fscanf(f_n, "%d", &numbers[i][j]);
		}
	}
	
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			picture[i][j] = chs[numbers[i][j]];
		}
		picture[i][j] = '\0';
	}
	
	for (i = 0; i < ROWS; i++)
	{
		fprintf(stdout, "%s\n", picture[i]);
		fprintf(f_p, "%s\n", picture[i]);
	}
	
	if (fclose(f_n) != 0)
	{
		fprintf(stderr, "Error closing \"%s\" file.\n", name_n);
		exit(EXIT_FAILURE);
	}
	if (fclose(f_p) != 0)
	{
		fprintf(stderr, "Error closing \"%s\" file.\n", name_p);
		exit(EXIT_FAILURE);
	}
	printf("Done.\n");
	
	return 0;
}
