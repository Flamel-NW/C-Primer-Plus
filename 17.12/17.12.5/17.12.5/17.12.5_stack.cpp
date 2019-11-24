//《C Primer Plus》p631 17.12.5
// 17.12.5_stack.h -- stack 类型的实现

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "17.12.5_stack.h"


void InitializeStack(Stack * ps)
{
	strcpy_s(ps->items, "");
	ps->top = 0;
}

bool FullStack(const Stack * ps)
{
	return (ps->top == MAXSTACK - 1);
}

bool EmptyStack(const Stack * ps)
{
	return (ps->top == 0);
}

bool Push(Item item, Stack * ps)
{
	if (FullStack(ps))
	{
		return false;
	}
	else
	{
		ps->items[ps->top] = item;
		ps->top++;
		return true;
	}
}

bool Pop(Item * pitem, stack * ps)
{
	if (EmptyStack(ps))
	{
		return false;
	}
	else
	{
		*pitem = ps->items[ps->top - 1];
		ps->items[ps->top - 1] = '\0';
		ps->top--;
		return true;
	}
}