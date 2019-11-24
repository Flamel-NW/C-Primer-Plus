//¡¶C Primer Plus¡·p490 14.18.4.a 
#include <stdio.h>
#define NAME 20
#define SIZE 5

struct person
{
	char first_name[NAME];
	char middle_name[NAME];
	char last_name[NAME];
};

struct insurance
{
	unsigned long No_;
	struct person name;
};

void print_file(struct insurance ptr[]);

int main(void)
{
	struct insurance list[SIZE] = 
	{
		{
			19634523, 
			{
				.first_name = "Michael",
				.last_name = "Jordan",
			}
		},
		{
			19590032,
			{
				.first_name = "Earvin",
				.last_name = "Johnson",
			}
		},
		{
			19760021,
			{
				.first_name = "Timothy",
				.middle_name = "Theodore",
				.last_name = "Duncan",
			}
		},
		{
			19840623,
			{
				.first_name = "LeBron",
				.middle_name = "Raymone",
				.last_name = "James",
			}
		},
		{
			32333436,
			{
				.first_name = "Shaquille",
				.last_name = "O'Neal",
			}
		}
	};
	
	print_file(list);
	
	return 0;
}

void print_file(struct insurance ptr[])
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (ptr[i].name.middle_name[0] != '\0')
		{
			printf("%s %c %s -- %lu\n",
					ptr[i].name.first_name,
					ptr[i].name.middle_name[0],
					ptr[i].name.last_name,
					ptr[i].No_);
		}
		else
		{
			printf("%s %s -- %lu\n",
					ptr[i].name.first_name,
					ptr[i].name.last_name,
					ptr[i].No_);
		}
	}
}
