//《C Primer Plus》p631 17.12.5
// 17.12.5_stack.h -- stack 类型的接口
#ifndef _SATCK_H_
#define _SATCK_H_
#include <stdbool.h>

typedef char Item;

#define MAXSTACK 100

typedef struct stack
{
	Item items[MAXSTACK];	// 储存信息
	int top;				// 第1个空位的索引
} Stack;

// 操作：		初始化栈
// 前提条件：	ps 指向一个栈
// 后置条件：	该栈被初始化为空
void InitializeStack(Stack * ps);

// 操作：		检查栈是否已满
// 前提条件：	ps 指向之前已被初始化的栈
// 后置条件：	如果栈已满，该函数返回 true；否则，返回 false
bool FullStack(const Stack * ps);

// 操作：		检查栈是否为空
// 前提条件：	ps 指向之前已被初始化的栈
// 后置条件：	如果栈为空，该函数返回 true；否则，返回 false
bool EmptyStack(const Stack * ps);

// 操作：		把项压入栈顶
// 前提条件：	ps 指向之前已被初始化的栈
//				item 是待压入栈顶的项
// 后置条件：	如果栈不满，把 item 放在栈顶，该函数返回 true；
//				否则，栈不变，该函数返回 false
bool Push(Item item, Stack * ps);

// 操作：		从栈顶删除项
// 前提条件：	ps 指向之前已被初始化的栈
// 后置条件：	如果栈不为空，把栈顶的 item 拷贝到 *pitem，删除栈顶的 item，该函数返回 true；
//				如果该操作后栈中没有项，则重置该栈为空。
//				如果删除操作之前栈为空，栈不变，该函数返回 false
bool Pop(Item * pitem, stack * ps);

#endif