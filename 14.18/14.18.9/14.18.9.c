//《C Primer Plus》p491 14.18.9
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#define NSIZE 20
#define PSIZE 12
#define CSIZE 4

struct seat
{
	int number;
	bool isbooked;
	char first_name[NSIZE];
	char last_name[NSIZE];
};

struct plane
{
	int n_empty;
	struct seat seats[PSIZE];
};

static int size = sizeof(struct plane);

void initialization(struct plane planes[], int nums, int p_seats);
int count_eseats(struct seat seats[], int nums);
void print_eseats(struct seat seats[], int nums);
void print_seats(struct seat seats[], int nums);
void assign(struct seat seats[], int nums, int * p_eseats);
void delete_seat(struct seat seats[], int nums, int * p_eseats);

int main(void)
{
	int choice1;
	int index;
	char choice2;
	struct plane giant[CSIZE];
//	initialization(giant, CSIZE, PSIZE);
	char p_names[CSIZE][NSIZE] =
	{
		"Plane.102.dat",
		"Plane.311.dat",
		"Plane.444.dat",
		"Plane.519.dat",
	};
	FILE * fplane;
	
	while (1)
	{
		puts("To choose a plane, enter its letter label:");
		puts("1) 102					2) 311");
		puts("3) 444					4) 519");
		puts("0) quit");
		if (scanf("%d", &choice1) == 0 || choice1 < 0 || choice1 > 4)
		{
			fprintf(stderr, "Input error!");
			continue;
		}
		else if (choice1 == 0)
		{
			break;
		}
		while (getchar() != '\n')
		{
			continue;
		}
		index = choice1 - 1;
		
		if ((fplane = fopen(p_names[index], "r+b")) == NULL)
		{
			fprintf(stderr, "Can\'t open %s file.\n", p_names[index]);
			exit(EXIT_FAILURE);
		}
		rewind(fplane);
		fread(&giant[index], size, 1, fplane);
		fclose(fplane);
		
		giant[index].n_empty = count_eseats(giant[index].seats, PSIZE);
		
		while (1)
		{
			puts("To choose a function, enter its letter label:");
			puts("a) Show number of empty seats");
			puts("b) Show list of empty seats");
			puts("c) Show alphabetical list of seats");
			puts("d) Assign a customer to a seat assignment");
			puts("e) Delete a seat assignment");
			puts("f) Save the seats infomation");
			puts("g) Quit");
			
			choice2 = getchar();
			while (getchar() != '\n')
			{
				continue;
			}
			
			switch (choice2)
			{
				case 'a':
					printf("%d seats is empty.\n\n", giant[index].n_empty);
					break;
				case 'b':
					print_eseats(giant[index].seats, PSIZE);
					break;
				case 'c':
					print_seats(giant[index].seats, PSIZE);
					break;
				case 'd':
					if (giant[index].n_empty == 0)
					{
						puts("Sorry! This plane is full.");
						continue;
					}
					assign(giant[index].seats, PSIZE, &giant[index].n_empty);
					break;
				case 'e':
					delete_seat(giant[index].seats, PSIZE, &giant[index].n_empty);
					break;
				case 'f':
					break;
				case 'g':
					break;
				default:
					fprintf(stderr, "Input error!");
					continue;
			}
			if (choice2 == 'f')
			{
				puts("Now the seating plan of this plane is:");
				print_seats(giant[index].seats, PSIZE);
				if ((fplane = fopen(p_names[index], "w+b")) == NULL)
				{
					fprintf(stderr, "Can\'t open %s file.\n", p_names[index]);
					exit(EXIT_FAILURE);
				}
				rewind(fplane);
				fwrite(&giant[index], size, 1, fplane);
				fclose(fplane);
				puts("Save it!\n");
				break;
			}
			if (choice2 == 'g')
			{
				puts("Return to the main menu.\n");
				break;
			}
		}
	}
	puts("Done.");
	
	return 0;
}

void initialization(struct plane planes[], int nums, int p_seats)
{
	struct seat empty = { 0, false, "\0", "\0" };
	
	int i, j;
	for (i = 0; i < nums; i++)
	{
		planes[i].n_empty = p_seats;
		for (j = 0; j < p_seats; j++)
		{
			planes[i].seats[j] = empty;
			planes[i].seats[j].number = j + 1;
		}
	}
}

int count_eseats(struct seat seats[], int nums)
{
	int ret = 0;
	
	int i;
	for (i = 0; i < nums; i++)
	{
		if (!seats[i].isbooked)
		{
			ret++;
		}
	}
	
	return ret;
}

void print_eseats(struct seat seats[], int nums)
{
	int i;
	for (i = 0; i < nums; i++)
	{
		if (!seats[i].isbooked)
		{
			printf("Seat. %d ", seats[i].number);
		}
	}
	printf("is empty.\n\n");
}

void print_seats(struct seat seats[], int nums)
{
	struct seat * temp;
	struct seat * ptr[nums];
	
	int i, j;
	for (i = 0, j = 0; i < nums; i++)
	{
		if (seats[i].isbooked)
		{
			ptr[j++] = &seats[i];
		}
	}
	
	int m, n;
	for (m = 0; m < j - 1; m++)
	{
		for (n = m + 1; m < j; m++)
		{
			if (strcmp(ptr[m]->first_name, ptr[n]->last_name) > 0)
			{
				temp = ptr[m];
				ptr[m] = ptr[n];
				ptr[n] = temp;
			}
		}
	}
	
	for (i = 0; i < j; i++)
	{
		printf("Seat. %d is booked by %s %s\n", ptr[i]->number, ptr[i]->first_name, ptr[i]->last_name);
	}
	putchar('\n');
}

void assign(struct seat seats[], int nums, int * p_eseats)
{
	int n;
	
	while (1)
	{
		fputs("Please enter the seat number (1 ~ 12): ", stdout);
		if (scanf("%d", &n) == 0 && n < 1 && n > PSIZE)
		{
			fprintf(stderr, "Input error!");
			exit(EXIT_FAILURE);
		}
		if (seats[n - 1].isbooked == true)
		{
			puts("Sorry! This seat has already been booked.");
			puts("You can try again.");
			continue;
		}
		puts("Please enter the customer\'s first name:");
		scanf("%s", seats[n - 1].first_name);
		puts("Please enter the customer\'s last name:");
		scanf("%s", seats[n - 1].last_name);
		seats[n - 1].isbooked = true;
		(*p_eseats)--;
		puts("Book it!\n");
		break;
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

void delete_seat(struct seat seats[], int nums, int * p_eseats)
{
	int n;
	
	while (1)
	{
		fputs("Please enter the seat number (1 ~ 12): ", stdout);
		if (scanf("%d", &n) == 0 && n < 1 && n > PSIZE)
		{
			fprintf(stderr, "Input error!");
			exit(EXIT_FAILURE);
		}
		if (seats[n - 1].isbooked == false)
		{
			puts("Sorry! This seat has already been empty.");
			puts("You can try again.");
			continue;
		}
		seats[n - 1].isbooked = false;
		(*p_eseats)++;
		puts("Delete it!\n");
		break;
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

//我觉得这个程序已经比较适合分别放在几个文件里了，可以同时支持第八题 
