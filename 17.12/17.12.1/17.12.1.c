//¡¶C Primer Plus¡·p631 17.12.1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film
{
	char title[TSIZE];
	int rating;
	struct film * next;
};

char * s_gets(char * st, int n);
void print_movie(struct film * ptf);

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];
	
	puts("Enter first movie title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc(sizeof(struct film));
		if (head == NULL)
		{
			head = current;
		}
		else
		{
			prev->next = current;
		}
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while (getchar() != '\n')
		{
			continue;
		}
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}
	
	if (head == NULL)
	{
		printf("No data entered.");
	}
	else
	{
		printf("Here is the movie list:\n");
	}
	current = head;
	while (current != NULL)
	{
		printf("Movie: %s Ratime: %d\n", current->title, current->rating);
		current = current->next;
	}
	current = head;
	print_movie(current);
	
	current = head;
	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}
	puts("Bye!");
	
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
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

void print_movie(struct film * ptf)
{
	if (ptf != NULL)
	{
		print_movie(ptf->next);
		printf("Movie: %s Ratime: %d\n", ptf->title, ptf->rating);
	}
}
