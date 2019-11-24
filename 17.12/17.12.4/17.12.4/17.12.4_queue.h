//��C Primer Plus��p631 17.12.4
// 17.12.4_Queue.h -- Queue ���͵Ľӿ�
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef struct item
{
	long arrive;		// һλ�˿ͼ�����е�ʱ��
	int processtime;	// �ù˿���ѯʱ���ѵ�ʱ��
} Item;

#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef struct queue
{
	Node * front;	// ָ����������ָ��
	Node * rear;	// ָ�����β���ָ��
	int items;		// �����е�����
} Queue;

// ������		��ʼ������
// ǰ��������	pq ָ��һ������
// ����������	���б���ʼ��Ϊ��
void InitializeQueue(Queue * pq);

// ������		�������Ƿ�����
// ǰ��������	pq ָ��֮ǰ�ѱ���ʼ���Ķ���
// ����������	������������򷵻� true�����򷵻� false
bool QueueIsFull(const Queue * pq);

// ������		�������Ƿ�Ϊ��
// ǰ��������	pq ָ��֮ǰ�ѱ���ʼ���Ķ���
// ����������	�������Ϊ���򷵻� true�����򷵻� false
bool QueueIsEmpty(const Queue * pq);

// ������		ȷ�������е�����
// ǰ��������	pq ָ��֮ǰ�ѱ���ʼ���Ķ���
// ����������	���ض����е�����
int QueueItemCount(const Queue * pq);

// ������		�ڶ���ĩβ�����
// ǰ��������	pq ָ��֮ǰ�ѱ���ʼ���Ķ���
//				item ��Ҫ������ڶ���ĩβ����
// ����������	������в�Ϊ�գ�item ��������ڶ��е�ĩβ���ú������� true��
//				���򣬶��в��ı䣬�ú������� false
bool EnQueue(Item item, Queue * pq);

// ������		�Ӷ��еĿ�ͷɾ����
// ǰ��������	pq ָ��֮ǰ�ѱ���ʼ���Ķ���
// ����������	������в�Ϊ�գ�
//				�����׶˵� item ���������� *ptiem �У�����ɾ�����Һ������� true
//				����ò���ʹ�ö���Ϊ�գ������ö���Ϊ��
//				��������ڲ���ǰΪ�գ��ú������� false
bool DeQueue(Item * pitem, Queue * pq);

// ������		��ն���
// ǰ��������	pq ָ��֮ǰ�ѱ���ʼ���Ķ���
// ����������	���б����
void EmptyTheQueue(Queue * pq);

#endif