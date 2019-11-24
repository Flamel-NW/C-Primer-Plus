//��C Primer Plus��p631 17.12.3
// 17.12.3_list.cpp -- ֧����������ĺ���

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "17.12.3_list.h"

// �ӿں���
// ����������Ϊ��
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

// �������Ϊ�գ�����true
bool ListIsEmpty(const List * plist)
{
	return (plist->items == 0);
}

// �����������������true
bool ListIsFull(const List * plist)
{
	return (plist->items == MAXSIZE)
}

// ���ؽڵ������ 
unsigned int ListItemCount(const List * plist)
{
	return plist->items;
}

// ����������Ľڵ㣬�������������plistָ�������ĩβ
void AddItem(Item item, List * plist)
{
	plist->entries[plist->items++] = item;
}

// ����ÿ���ڵ㲢ִ��pfunָ��ĺ��� 
void Traverse(const List * plist, void (*pfun) (Item item))
{
	int i;
	for (i = 0; i < plist->items; i++)
	{
		(*pfun) (plist->entries[i]);
	}
}

// ��������ָ��ΪNULL 
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