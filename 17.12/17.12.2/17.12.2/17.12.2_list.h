//��C Primer Plus��p631 17.12.2
// 17.12.2_list.h -- ���������͵�ͷ�ļ� 
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>

// �ض����������

#define TSIZE 45  // �����Ӱ���������С 
struct film
{
	char title[TSIZE];
	int rating;
};

// һ�����Ͷ��� 

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct list
{
	Node * head;
	Node * end;
} List;

// ����ԭ��

// ������		��ʼ��һ������ 
// ǰ�������� 	plist ָ��һ������ 
// ����������   �����ʼ��Ϊ�� 
void InitializeList(List * plist);

// ������		ȷ�������Ƿ�Ϊ�ն��壬plist ָ��һ���ѳ�ʼ��������
// ����������	�������Ϊ�գ��ú������� true�����򷵻� false 
bool ListIsEmpty(const List * plist);

// ������	 	ȷ�������Ƿ�������plist ָ��һ���ѳ�ʼ��������
// ����������	��������������ú�������true�����򷵻� false 
bool ListIsFull(const List * plist);

// ������		ȷ�������е�������plist ָ��һ���ѳ�ʼ��������
// ����������	�ú������������е����� 
unsigned int ListItemCount(const List * plist);

// ������		�������ĩβ�����
// ǰ��������	item ��һ��������������е��plist ָ��һ���ѳ�ʼ��������
// ����������	������ԣ��ú���������ĩβ���һ����ҷ��� true�����򷵻� false 
bool AddItem(Item item, List * plist);

// ������		�Ѻ��������������е�ÿһ��
//				plist ָ��һ���ѳ�ʼ��������
//				pfun ָ��һ���������ú�������һ�� Item ���͵Ĳ��������޷���ֵ 
// ����������	pfun ָ��ĺ��������������е�ÿһ��һ�� 
void Traverse(const List * plist, void(*pfun) (Item item));

// ������		�ͷ��ѷ�����ڴ�
//				plist ָ��һ���ѳ�ʼ��������
// ����������	�ͷ���Ϊ�������������ڴ棬��������Ϊ��
void EmptyTheList(List * plist);

#endif
