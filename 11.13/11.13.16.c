//¡¶C Primer Plus¡·p372 11.13.16
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ROWS 10
#define COLS 20

void toupper_strs(char strings[][COLS], int rows);
void tolower_strs(char strings[][COLS], int rows);
int main(int argc, char * argv [])
{
	char input[ROWS][COLS];
	int row;
	
	for (row = 0; row < ROWS && (fgets(input[row], COLS, stdin)) != NULL; row++)
	{
		continue;
	}
	
	if (!(strcmp(argv[1], "-u")))
	{
		toupper_strs(input, row);
	}
	else if (!(strcmp(argv[1], "-l")))
	{
		tolower_strs(input, row);
	}
	
	for (row = 0; input[row][0] && row < ROWS; row++)
	{
		fputs(input[row], stdout);
	}
	
	return 0;
}

void toupper_strs(char strings[][COLS], int rows)
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			strings[i][j] = toupper(strings[i][j]);
		}
	}
}

void tolower_strs(char strings[][COLS], int rows)
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			strings[i][j] = tolower(strings[i][j]);
		}
	}
}
