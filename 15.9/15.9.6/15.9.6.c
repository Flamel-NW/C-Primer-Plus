//《C Primer Plus》p519 15.9.6
#include <stdio.h>
#include <stdbool.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OFF 0
#define ON 1

struct typeface 
{
	unsigned int font : 8 ;
	unsigned int size : 7 ;
	unsigned int : 0 ;
	unsigned int alignment : 2 ;
	bool bold : 1 ;
	bool italic : 1 ;
	bool underline : 1 ;
};

//	学习这种写法 
const static char * align[] = { "left", "center", "right" };
const static char * open[] = { "off", "on" };

void show_type_menu(const struct typeface * type);
void get_change(struct typeface * type, char choice);
void change_font(unsigned int * font);
void change_size(unsigned int * size);
void change_alignment(unsigned int * alignment);

int main(void)
{
	struct typeface word = { 1, 12, LEFT, OFF, OFF, OFF };
	char ch;
	
	show_type_menu(&word);
	while ((ch = getchar()) != EOF && ch != 'q')
	{
		while (getchar() != '\n')
		{
			continue;
		}
		get_change(&word, ch);
		show_type_menu(&word);
	}
	puts("Bye!.");
	
	return 0;
}

void show_type_menu(const struct typeface * type)
{
	puts("  ID SIZE ALIGNMENT   B    I    U");
	printf("%4u %4u %8s %4s %4s %4s\n\n", type->font, type->size, align[type->alignment]
							, open[type->bold], open[type->italic], open[type->underline]);
							
	puts("f) change font		s) change size		a) change alignment");
	puts("b) toggle bold		i) toggle italic	u) toggle underline");
	puts("q) quit");
}

void get_change(struct typeface * type, char choice)
{
	unsigned int temp;
	
	switch (choice)
	{
		case 'f':
			change_font(&temp);
			type->font = temp;
			break;
		case 's':
			change_size(&temp);
			type->size = temp;
			break;
		case 'a':
			change_alignment(&temp);
			type->alignment = temp;
			break;
		case 'b':
			type->bold = (type->bold) ? false : true;
			break;
		case 'i':
			type->italic = (type->italic) ? false : true;
			break;
		case 'u':
			type->underline = (type->underline) ? false : true;
			break;
		default:
			puts("Input error!");
			puts("Try again.");
			break;
	}
}

void change_font(unsigned int * font)
{
	unsigned int id_font;
	puts("Enter font ID (0 - 255): ");
	if (scanf("%u", &id_font) == 0 || id_font > 255)
	{
		puts("Input error!");
		puts("Try again.");
	}
	else
	{
		*font = id_font;
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

void change_size(unsigned int * size)
{
	unsigned int n_size;
	puts("Enter font size (0 - 127): ");
	if (scanf("%u", &n_size) == 0 || n_size > 127)
	{
		puts("Input error!");
		puts("Try again.");
	}
	else
	{
		*size = n_size;
	}
	while (getchar() != '\n')
	{
		continue;
	}
}

void change_alignment(unsigned int * alignment)
{
	char choice;
	puts("Select alignment:");
	puts("l) left		c) center	r) right");
	choice = getchar();
	while (getchar() != '\n')
	{
		continue;
	}
	switch (choice)
	{
		case 'l':
			*alignment = LEFT;
			break;
		case 'c':
			*alignment = CENTER;
			break;
		case 'r':
			*alignment = RIGHT;
			break;
		default:
			puts("Input error!");
			puts("Try again.");
			break;
	}
}
