//¡¶C Primer Plus¡·p490 14.18.3
#include <stdio.h>
#include <string.h>
#define MAXTITL 20
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char * s_gets(char * st, int n);
void sort_title(struct book * pts[], struct book books[], int nums);
void sort_value(struct book * pts[], struct book books[], int nums);

int main(void)
{
	struct book library[MAXBKS];
	struct book * ptbook[MAXBKS];
	int count = 0;
	int index;
	
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
			&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
		{
			continue;
		}
		if (count < MAXBKS)
		{
			printf("Enter the next title.\n");
		}
	}
	
	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		}
		printf("\n");

		for (index = 0; index < count; index++)
		{
			ptbook[index] = &library[index];
		}
		sort_title(ptbook, library, count);
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", ptbook[index]->title,
					ptbook[index]->author, ptbook[index]->value);
		}
		printf("\n");
		
		for (index = 0; index < count; index++)
		{
			ptbook[index] = &library[index];
		}
		sort_value(ptbook, library, count);
		for (index = 0; index < count; index++)
		{
			printf("%s by %s: $%.2f\n", ptbook[index]->title,
					ptbook[index]->author, ptbook[index]->value);
		}
		printf("\n");
	}
	else
	{
		printf("No books? Too bad.\n");
	}
	
	return 0;
}

void sort_title(struct book * pts[], struct book books[], int nums)
{
	struct book * temp;
	int i, j;
	for (i = 0; i < nums - 1; i++)
	{
		for (j = i + 1; j < nums; j++)
		{
			if (strcmp(books[i].title, books[j].title) > 0)
			{
				temp = pts[i];
				pts[i] = pts[j];
				pts[j] = temp;
			}
		}
	}
}

void sort_value(struct book * pts[], struct book books[], int nums)
{
	struct book * temp;
	int i, j;
	for (i = 0; i < nums - 1; i++)
	{
		for (j = i + 1; j < nums; j++)
		{
			if (books[i].value > books[j].value)
			{
				temp = pts[i];
				pts[i] = pts[j];
				pts[j] = temp;
			}
		}
	}
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
