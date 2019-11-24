// 17.12.7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//《C Primer Plus》p631 17.12.7
// 17.12.7.cpp -- 使用二叉查找树
// 与17.12.7_tree.cpp一起编译

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include "17.12.7_tree.h"

void listall(Tree * tree);
void printitem(Item item);
void seekword(Tree * tree);

int main()
{
	FILE * fp;
	errno_t err = fopen_s(&fp, "words.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Can't open \"words.txt\" file.\n");
		exit(EXIT_FAILURE);
	}

	Tree article;
	Item temp;
	InitializeTree(&article);

	while (fscanf_s(fp, "%s", temp.word, SLEN) != EOF)
	{
		temp.nums = 1;
		if (AddItem(&temp, &article) == false)
		{
			fprintf(stderr, "Problem allocating memory.\n");
			break;
		}
		if (TreeIsFull(&article))
		{
			puts("The Tree is now full.");
			break;
		}
	}
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing \"words.txt\" file.\n");
		exit(EXIT_FAILURE);
	}

	while (true)
	{
		char choice;

		puts("1：List all words and times.");
		puts("2：Seek word and times.");
		puts("3：quit");

		choice = getchar();
		while (getchar() != '\n')
		{
			continue;
		}
		switch (choice)
		{
			case '1':
				listall(&article);
				break;
			case '2':
				seekword(&article);
				break;
			case '3':
				break;
			default:
				break;
		}
		if (choice == '3')
		{
			break;
		}
	}
	puts("Bye!");

	return 0;
}

void printitem(Item item)
{
	printf("%s -- %d\n", item.word, item.nums);
}

void listall(Tree * tree)
{
	Traverse(tree, printitem);
}

void seekword(Tree * tree)
{
	Item temp;

	puts("Enter the word you want:");
	scanf_s("%s", temp.word, SLEN);
	while (getchar() != '\n')
	{
		continue;
	}
	if (InTree(&temp, tree))
	{
		printf("%d times\n", ItemCount(&temp, tree));
	}
	else
	{
		puts("This word didn't exist!");
	}
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
