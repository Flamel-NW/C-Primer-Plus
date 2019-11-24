//¡¶C Primer Plus¡·p491 14.18.6
#include <stdio.h>
#include <stdlib.h>
#define TSIZE 19
#define NSIZE 20

struct name
{
	char first_name[NSIZE];
	char last_name[NSIZE];
};

struct player
{
	struct name n_player;
	int at_bat;
	int hits;
	int bases;
	int rbi_;
	float hit_pct;
};

void initialization(struct player players[], int nums);
void read_in(FILE * src, struct player players[], int nums);
void get_hit_pct(struct player players[], int nums);
void print_team(struct player players[], int nums);

int main(void)

{
	FILE * fp;
	char file[] = "Team_info.txt";
	struct player team[TSIZE];
	
	initialization(team, TSIZE);
	
	if ((fp = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", file);
		exit(EXIT_FAILURE);
	}
	
	read_in(fp, team, TSIZE);
	get_hit_pct(team, TSIZE);
	print_team(team, TSIZE);
	
	return 0;
}

void initialization(struct player players[], int nums)
{
	struct player empty =
	{
		{ "\0", "\0" },
		0, 0, 0, 0, 0
	};
	
	int i;
	for (i = 0; i < nums; i++)
	{
		players[i] = empty;
	}
}

void read_in(FILE * src, struct player players[], int nums)
{
	int No_;
	int temp;
	char ch;
	
	do
	{
		if ((fscanf(src, "%d", &No_)) == 0 && No_ < 0 && No_ > 18)
		{
			fprintf(stderr, "Input error!\n");
			exit(EXIT_FAILURE);
		}
		
		fscanf(src, "%s", players[No_].n_player.first_name);
		fscanf(src, "%s", players[No_].n_player.last_name);
		
		if ((fscanf(src, "%d", &temp)) == 0)
		{
			fprintf(stderr, "Input error!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			players[No_].at_bat += temp;
		}
		
		if ((fscanf(src, "%d", &temp)) == 0)
		{
			fprintf(stderr, "Input error!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			players[No_].hits += temp;
		}
		
		if ((fscanf(src, "%d", &temp)) == 0)
		{
			fprintf(stderr, "Input error!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			players[No_].bases += temp;
		}
		
		if ((fscanf(src, "%d", &temp)) == 0)
		{
			fprintf(stderr, "Input error!\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			players[No_].rbi_ += temp;
		}
		
		while ((ch = getc(src)) != '\n' && ch != EOF)
		{
			continue;
		}
	} while (ch != EOF);
}

void get_hit_pct(struct player players[], int nums)
{
	int i;
	for (i = 0; i < nums; i++)
	{
		players[i].hit_pct = ((float) players[i].hits) / ((float) players[i].at_bat);
	}
}

void print_team(struct player players[], int nums)
{
	int i;
	for (i = 0; i < nums; i++)
	{
		printf("No.%d: %s %s :\n", i, players[i].n_player.first_name, players[i].n_player.last_name);
		printf("At_Bats: %d\n", players[i].at_bat);
		printf("Hits: %d\n", players[i].hits);
		printf("Bases: %d\n", players[i].bases);
		printf("R.B.I.: %d\n", players[i].rbi_);
		printf("Hit percentage: %.2f\n\n", players[i].hit_pct);
	}
}
