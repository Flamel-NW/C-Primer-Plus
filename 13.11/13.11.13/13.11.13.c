//¡¶C Primer Plus¡·p438 13.11.13
#include <stdio.h>
#include <stdlib.h>
#define NAME 20

void count(FILE * file, int * row, int * col);
void file_n(FILE * file_n, int row, int col, int nums[row][col]);
char n_p(int row, int col, int nums[row][col], char picture[row][col + 1]); 
void p_file(FILE * file_p, int row, int col, char picture[row][col + 1]);
int main(void)
{
	FILE * f_n, * f_p;
	char name_n[NAME] = "numbers.txt";
	char name_p[NAME] = "picture.txt";
	
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
	
	int rows = 0;
	int cols = 0;
	count(f_n, &rows, &cols);
	rewind(f_n);
	
	int numbers[rows][cols];
	file_n(f_n, rows, cols, numbers);
	
	char chars[rows][cols + 1];
	n_p(rows, cols, numbers, chars);
	
	p_file(f_p, rows, cols, chars);
	
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

void count(FILE * file, int * row, int * col)
{
	char ch;
	while ((ch = getc(file)) != EOF)
	{
		if (isdigit(ch))
		{
			(*col)++;
		}
		else if (ch == '\n')
		{
			(*row)++;
			*col = 0;
		}
	}
	(*row)++;
}

void file_n(FILE * file_n, int row, int col, int nums[row][col])
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fscanf(file_n, "%d", &nums[i][j]);
		}
	}
}

char n_p(int row, int col, int nums[row][col], char picture[row][col + 1])
{
	char chs[] = " .':~*=&%#";
	
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			picture[i][j] = chs[nums[i][j]];
		}
		picture[i][j] = '\0';
	}
}

void p_file(FILE * file_p, int row, int col, char picture[row][col + 1])
{
	int i;
	for (i = 0; i < row; i++)
	{
		fprintf(stdout, "%s\n", picture[i]);
		fprintf(file_p, "%s\n", picture[i]);
	}
}
