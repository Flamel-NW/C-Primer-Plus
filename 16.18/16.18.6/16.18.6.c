//¡¶C Primer Plus¡·p564 16.18.6
#include <stdio.h>
#include <stdlib.h>
#define NSIZE 40
#define SSIZE 5

struct names
{
	char first[NSIZE];
	char last[NSIZE];
};

int mycomp(const void * p1, const void * p2);
void show_names(struct names people[], int n);

int main(void)
{
	struct names staff[SSIZE] = 
	{
		{ "Michael", "Jordan" },
		{ "Earvin", "Johnson" },
		{ "Tim", "Duncan" },
		{ "LeBron", "James" },
		{ "Shaquille", "O\'Neal" }
	};
	qsort(staff, SSIZE, sizeof(struct names), mycomp);
	show_names(staff, SSIZE);
	
	return 0;
}

int mycomp(const void * p1, const void * p2)
{
	const struct names * ps1 = (const struct names *) p1;
	const struct names * ps2 = (const struct names *) p2;
	int res;
	res = strcmp(ps1->last, ps2->last);
	if (res != 0)
	{
		return res;
	}
	else
	{
		return strcmp(ps1->first, ps2->first);
	}
}

void show_names(struct names people[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s %s\n", people[i].first, people[i].last);
	}
}
