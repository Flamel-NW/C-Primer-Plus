//��C Primer Plus��p631 17.12.5
// 17.12.5_stack.h -- stack ���͵Ľӿ�
#ifndef _SATCK_H_
#define _SATCK_H_
#include <stdbool.h>

typedef char Item;

#define MAXSTACK 100

typedef struct stack
{
	Item items[MAXSTACK];	// ������Ϣ
	int top;				// ��1����λ������
} Stack;

// ������		��ʼ��ջ
// ǰ��������	ps ָ��һ��ջ
// ����������	��ջ����ʼ��Ϊ��
void InitializeStack(Stack * ps);

// ������		���ջ�Ƿ�����
// ǰ��������	ps ָ��֮ǰ�ѱ���ʼ����ջ
// ����������	���ջ�������ú������� true�����򣬷��� false
bool FullStack(const Stack * ps);

// ������		���ջ�Ƿ�Ϊ��
// ǰ��������	ps ָ��֮ǰ�ѱ���ʼ����ջ
// ����������	���ջΪ�գ��ú������� true�����򣬷��� false
bool EmptyStack(const Stack * ps);

// ������		����ѹ��ջ��
// ǰ��������	ps ָ��֮ǰ�ѱ���ʼ����ջ
//				item �Ǵ�ѹ��ջ������
// ����������	���ջ�������� item ����ջ�����ú������� true��
//				����ջ���䣬�ú������� false
bool Push(Item item, Stack * ps);

// ������		��ջ��ɾ����
// ǰ��������	ps ָ��֮ǰ�ѱ���ʼ����ջ
// ����������	���ջ��Ϊ�գ���ջ���� item ������ *pitem��ɾ��ջ���� item���ú������� true��
//				����ò�����ջ��û��������ø�ջΪ�ա�
//				���ɾ������֮ǰջΪ�գ�ջ���䣬�ú������� false
bool Pop(Item * pitem, stack * ps);

#endif