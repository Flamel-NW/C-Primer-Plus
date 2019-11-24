//《C Primer Plus》p631 17.12.3
// 17.12.3_list.cpp -- 支持链表操作的函数

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "17.12.3_list.h"

// 接口函数
// 把链表设置为空
void InitializeList(List * plist)
{
	plist->items = 0;

	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		strcpy_s(plist->entries[i].title, "");
		plist->entries[i].rating = 0;
	}
}

// 如果链表为空，返回true
bool ListIsEmpty(const List * plist)
{
	return (plist->items == 0);
}

// 如果链表已满，返回true
bool ListIsFull(const List * plist)
{
	return (plist->items == MAXSIZE)
}

// 返回节点的数量 
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

// 创建储存项的节点，并将其添加至有plist指向的链表末尾
void AddItem(Item item, List * plist)
{
	plist->entries[plist->items++] = item;
}

// 访问每个节点并执行pfun指向的函数 
void Traverse(const List * plist, void (*pfun) (Item item))
{
	int i;
	for (i = 0; i < plist->items; i++)
	{
		(*pfun) (plist->entries[i]);
	}
}

// 设置链表指针为NULL 
void EmptyTheList(List * plist)
{
	plist->items = 0;

	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		strcpy_s(plist->entries[i].title, "");
		plist->entries[i].rating = 0;
	}
}