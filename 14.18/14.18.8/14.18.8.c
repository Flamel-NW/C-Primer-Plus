//《C Primer Plus》p491 14.18.8
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#define NSIZE 20
#define PSIZE 12

struct seat
{
	int number;
	bool isbooked;
	char first_name[NSIZE];
	char last_name[NSIZE];
};

static int size = sizeof(struct seat);
static int n_empty = PSIZE;

//void initialization(struct seat seats[], int nums);
int count_eseats(struct seat seats[], int nums);
void print_eseats(struct seat seats[], int nums);
void print_seats(struct seat seats[], int nums);
void assign(struct seat seats[], int nums);
void delete_seat(struct seat seats[], int nums);

int main(void)
{
	extern int n_empty;
	char choice;
	struct seat plane[PSIZE];
	FILE * fplane;
//	initialization(plane, PSIZE);
	
	if ((fplane = fopen("plane.dat", "r+b")) == NULL)
	{
		fputs("Can\'t open plane.dat file.\n", stderr);
		exit(EXIT_FAILURE);
	}
	rewind(fplane);
	fread(plane, size, PSIZE, fplane);
	fclose(fplane);
	
	n_empty = count_eseats(plane, PSIZE);
	
	while (1)
	{
		puts("To choose a function, enter its letter label:");
		puts("a) Show number of empty seats");
		puts("b) Show list of empty seats");
		puts("c) Show alphabetical list of seats");
		puts("d) Assign a customer to a seat assignment");
		puts("e) Delete a seat assignment");
		puts("f) Quit");
		
		choice = getchar();
		while (getchar() != '\n')
		{
			continue;
		}
		
		switch (choice)
		{
			case 'a':
				printf("%d seats is empty.\n\n", n_empty);
				break;
			case 'b':
				print_eseats(plane, PSIZE);
				break;
			case 'c':
				print_seats(plane, PSIZE);
				break;
			case 'd':
				if (n_empty == 0)
				{
					puts("Sorry! This plane is full.");
					continue;
				}
				assign(plane, PSIZE);
				break;
			case 'e':
				delete_seat(plane, PSIZE);
				break;
			case 'f':
				break;
			default:
				fprintf(stderr, "Input error!");
				continue;
		}
		if (choice == 'f')
		{
			break;
		}
	}
	if ((fplane = fopen("plane.dat", "w+b")) == NULL)
	{
		fputs("Can\'t open plane.dat file.\n", stderr);
		exit(EXIT_FAILURE);
	}
	rewind(fplane);
	fwrite(plane, size, PSIZE, fplane);
	fclose(fplane);
	puts("Done.");
	
	return 0;
}

//void initialization(struct seat seats[], int nums)
//{
//	struct seat empty = { 0, false, "\0", "\0" }; 	//	结构只有在初始化时才能这样赋值 
//	
//	int i;
//	for (i = 0; i < nums; i++)
//	{
//		seats[i] = empty;	//	但是任何时候都可以这样赋值
//		seats[i].number = i + 1;
//	}
//}

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

void assign(struct seat seats[], int nums)
{
	extern int n_empty;
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
		n_empty--;
		puts("Book it!\n");
		break;
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

void delete_seat(struct seat seats[], int nums)
{
	extern int n_empty;
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
		n_empty++;
		puts("Delete it!\n");
		break;
	}
	while (getchar() != '\n')
	{
		continue;
	}
}
