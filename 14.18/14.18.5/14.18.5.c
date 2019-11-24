//¡¶C Primer Plus¡·p490 14.18.5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NSIZE 20
#define CSIZE 4

struct name
{
	char first_name[NSIZE];
	char last_name[NSIZE];
};

struct student
{
	struct name n_student;
	float grade[3];
	float average;
};

void get_grades(struct student students[], int nums);
void averages(struct student students[], int nums);
void print_class(struct student students[], int nums);
void class_average(struct student students[], int nums);

int main(void)
{
	struct student oneclass[CSIZE] =
	{
		{
			.n_student = { "Michael", "Jordan" }
		},
		{
			.n_student = { "Magic", "Johnson" }
		},
		{
			.n_student = { "Tim", "Duncan" }
		},
		{
			.n_student = { "LeBron", "James" }
		}
	};
	
	get_grades(oneclass, CSIZE);
	averages(oneclass, CSIZE);
	print_class(oneclass, CSIZE);
	class_average(oneclass, CSIZE);
	
	return 0;
}

void get_grades(struct student students[], int nums)
{
	char f_name[NSIZE];
	char l_name[NSIZE];
	
	int i, j;
	for (i = 0; i < nums; i++)
	{
		printf("Please enter the name of a student: ");
		scanf("%s%s", f_name, l_name);
		for (j = 0; j < nums; j++)
		{
			if (strcmp(f_name, students[j].n_student.first_name) == 0 &&
				strcmp(l_name, students[j].n_student.last_name) == 0)
			{
				break;
			}
			else if (j == nums - 1)
			{
				fprintf(stderr, "Input error!\n");
				exit(EXIT_FAILURE);
			}
		}
		printf("Please enter his grades: ");
		scanf("%f%f%f", &students[j].grade[1], &students[j].grade[2], &students[j].grade[3]);
	}
}

void averages(struct student students[], int nums)
{
	int i, j;
	for (i = 0; i < nums; i++)
	{
		students[i].average = (students[i].grade[1] + students[i].grade[2] + students[i].grade[3]) / 3;
	}
}
 
void print_class(struct student students[], int nums)
{
	int i;
	for (i = 0; i < nums; i++)
	{
		printf("Name: %s %s\n", students[i].n_student.first_name, students[i].n_student.last_name);
		printf("Grades: %.2f %.2f %.2f\n", students[i].grade[1], students[i].grade[2], students[i].grade[3]);
		printf("Average: %.2f\n\n", students[i].average);
	}
}

void class_average(struct student students[], int nums)
{
	float c_all = 0;
	
	int i;
	for (i = 0; i < CSIZE; i++)
	{
		c_all += students[i].average;
	}
	printf("Class average: %.2f\n", c_all / CSIZE);
}

//Michael Jordan  Magic Johnson  Tim Duncan  LeBron James
