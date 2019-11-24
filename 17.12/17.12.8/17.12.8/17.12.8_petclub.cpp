// 17.12.8_petclub.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//《C Primer Plus》p631 17.12.8
// 17.12.8_petclub.cpp -- 使用二叉查找树
// 与17.12.8_tree.cpp一起编译

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "17.12.8_tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpets(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main()
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while ((choice = menu()) != 'q')		// 学习这一种菜单方式
	{
		switch (choice)
		{
			case 'a':
				addpet(&pets);
				break;
			case 'l':
				showpets(&pets);
				break;
			case 'f':
				findpets(&pets);
				break;
			case 'n':
				printf("%d pets in club\n", TreeItemCount(&pets));
				break;
			case 'd':
				droppet(&pets);
				break;
			default:
				puts("Switching error");
				break;
		}
	}
	DeleteAll(&pets);
	puts("Bye.");

	return 0;
}

char menu(void)
{
	int ch;

	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your chioce:");
	puts("a) add a pet			l) show list of pets");
	puts("n) number of pets		f) find pets");
	puts("d) delete a pet			q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')
		{
			continue;
		}
		ch = tolower(ch);
		if (strchr("alrfndq", ch) == NULL)
		{
			puts("Please enter an a, l, f, n, d, or q:");
		}
		else
		{
			break;
		}
	}
	if (ch == EOF)
	{
		ch = 'q';
	}

	return ch;
}

void addpet(Tree * pt)
{
	Item temp;

	if (TreeIsFull(pt))
	{
		puts("No room in the club!");
	}
	else
	{
		puts("Please enter name of pet:");
		s_gets(temp.petname, SLEN);
		puts("Please enter pet kind:");
		s_gets(temp.petkind[0], SLEN);
		uppercase(temp.petname);
		uppercase(temp.petkind[0]);
		AddItem(&temp, pt);
	}
}

void showpets(const Tree * pt)
{
	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
	}
	else
	{
		Traverse(pt, printitem);
	}
}

void printitem(Item item)
{
	int i;
	for (i = 0; i < item.nums; i++)
	{
		printf("Pet: %-19s  Kind: %-19s\n", item.petname, item.petkind[i]);
	}
}

void findpets(const Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to find:");
	s_gets(temp.petname, SLEN);
	uppercase(temp.petname);
	if (!PrintItem(&temp, pt))
	{
		printf("%s is not a member.\n", temp.petname);
	}
}

void droppet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("Please enter name of pet you wish to delete:");
	s_gets(temp.petname, SLEN);
	uppercase(temp.petname);
	if (DeleteItem(&temp, pt))
	{
		printf("%s is dropped from the club.\n", temp.petname);
	}
	else
	{
		printf("%s is not a member.\n", temp.petname);
	}
}

void uppercase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
