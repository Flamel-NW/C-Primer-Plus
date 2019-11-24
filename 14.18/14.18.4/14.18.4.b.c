//¡¶C Primer Plus¡·p490 14.18.4.b 
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

void print_file(struct insurance player);

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
	
	int i;
	for (i = 0; i < SIZE; i++)
	{
		print_file(list[i]);
	}
	
	return 0;
}

void print_file(struct insurance player)
{
	if (player.name.middle_name[0] != '\0')
	{
		printf("%s %c %s -- %lu\n",
				player.name.first_name,
				player.name.middle_name[0],
				player.name.last_name,
				player.No_);
	}
	else
	{
		printf("%s %s -- %lu\n",
				player.name.first_name,
				player.name.last_name,
				player.No_);
	}
}
