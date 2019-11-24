//《C Primer Plus》p491 14.18.7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;
	int filecount;
	FILE * pbooks;
	int size = sizeof(struct book);
	
	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can\'t open book.dat file.\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
		{
			puts("Current contents of book.dat:");
		}
		printf("%s by %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);
		count++;
	}
	fclose(pbooks);
	
	if (count != 0)
	{
		puts("Do you want to alter any book?");
		fputs("If you do. Enter its number (enter \'q\' to refuse): ", stdout);
		while (scanf("%d", &index) != 0)
		{
			index--;
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
			puts("If you want to delete it. Press [enter] at the start of a line.");
			puts("Or enter new book titles.");
			while (getchar() != '\n')
			{
				continue;
			}
			if (s_gets(library[index].title, MAXTITL) != NULL && library[index].title[0] != '\0')
			{
				puts("Now enter the author.");
				s_gets(library[index].author, MAXAUTL);
				puts("Now enter the value.");
				scanf("%f", &library[index].value);
				while (getchar() != '\n')
				{
					continue;
				}
				puts("Do you still want to alter any book?");
				fputs("If you do. Enter its number (enter \'q\' to refuse): ", stdout);
			}
			else if (library[index].title[0] == '\0')
			{
				for ( ; index <= count; index++)
				{
					library[index] = library[index + 1];
				}
				count--;
				puts("Delete it!");
				puts("Do you still want to alter any book?");
				fputs("If you do. Enter its number (enter \'q\' to refuse): ", stdout);
			}
		}
		while (getchar() != '\n')
		{
			continue;
		}
	}
	
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(EXIT_FAILURE);
	}
	
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count].value);
		count++;
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < MAXBKS)
		{
			puts("Enter the next title.");
		}
	}
	
	if ((pbooks = fopen("book.dat", "w+b")) == NULL)
	{
		fputs("Can\'t open book.dat file.\n", stderr);
		exit(EXIT_FAILURE);
	}
	rewind(pbooks);
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);
		}
		fwrite(library, size, count, pbooks);
	}
	else
	{
		puts("No books? Too bad.\n");
	}
	
	puts("Bye.\n");
	fclose(pbooks);
	
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	
	if ((ret_val = fgets(st, n, stdin)) != NULL)
	{
		if ((find = strchr(st, '\n')) != NULL)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
			{
				continue;
			}
		}
	}
	
	return ret_val;
}

//		应注意代码的模块化 在14.18.8中实现 
