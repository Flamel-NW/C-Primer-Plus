//¡¶C Primer Plus¡·p519 15.9.7
#include <stdio.h>
#include <stdbool.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define OFF 0
#define ON 1

const static char * align[] = { "left", "center", "right" };
const static char * open[] = { "off", "on" };

void show_type_menu(unsigned long int * type);
void get_change(unsigned long int * type, char choice);
void change_font(unsigned int * font);
void change_size(unsigned int * size);
void change_alignment(unsigned int * alignment);

int main(void)
{
	unsigned long int word = 0xC01;
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

void show_type_menu(unsigned long int * type)
{
	puts("  ID SIZE ALIGNMENT   B    I    U");

	unsigned int mask_font = 0xFF;
	unsigned int mask_size = 0x7F << 8;
	unsigned int mask_alignment = 0x3 << 16;
	unsigned int mask_bold = 0x1 << 18;
	unsigned int mask_italic = 0x1 << 19;
	unsigned int mask_underline = 0x1 << 20;
	
	printf("%4lu %4lu %8s %4s %4s %4s\n\n", *type & mask_font, (*type & mask_size) >> 8
							, align[(*type & mask_alignment) >> 16], open[(*type & mask_bold) >> 18]
							, open[(*type & mask_italic) >> 19], open[(*type & mask_underline) >> 20]);
							
	puts("f) change font		s) change size		a) change alignment");
	puts("b) toggle bold		i) toggle italic	u) toggle underline");
	puts("q) quit");
}

void get_change(unsigned long int * type, char choice)
{
	unsigned int mask_font = 0xFF;
	unsigned int mask_size = 0x7F << 8;
	unsigned int mask_alignment = 0x3 << 16;
	unsigned int mask_bold = 0x1 << 18;
	unsigned int mask_italic = 0x1 << 19;
	unsigned int mask_underline = 0x1 << 20;
	
	unsigned int temp = 0;
	
	switch (choice)
	{
		case 'f':
			change_font(&temp);
			*type = *type & ~mask_font;
			*type = *type | temp;
			break;
		case 's':
			change_size(&temp);
			*type = *type & ~mask_size;
			*type = *type | temp << 8;
			break;
		case 'a':
			change_alignment(&temp);
			*type = *type & ~mask_alignment;
			*type = *type | temp << 16;
			break;
		case 'b':
			*type = *type ^ mask_bold;
			break;
		case 'i':
			*type = *type ^ mask_italic;
			break;
		case 'u':
			*type = *type ^ mask_underline;
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
