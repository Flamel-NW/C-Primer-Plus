//��C Primer Plus��p631 17.12.4
// 17.12.4_Queue.h -- Queue ���͵�ʵ��

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include "17.12.4_queue.h"

// �ֲ�����
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue * pq)
{
	return (pq->items == MAXQUEUE);
}

bool QueueIsEmpty(const Queue * pq)
{
	return (pq->items == 0);
}

int QueueItemCount(const Queue * pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue * pq)
{
	Node * pnew;

	if (QueueIsFull(pq))
	{
		return false;
	}
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))
	{
		pq->front = pnew;			// ��λ�ڶ��е��׶�
	}
	else
	{
		pq->rear->next = pnew;		// ���ӵ����е�β��
	}
	pq->rear = pnew;				// ��¼����β�˵�λ��
	pq->items++;					// ����������1

	return true;
}

bool DeQueue(Item * pitem, Queue * pq)
{
	Node * pt;

	if (QueueIsEmpty(pq))
	{
		return false;
	}
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
	{
		pq->rear = NULL;
	}

	return true;
}

// ��ն���
void EmptyTheQueue(Queue * pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
	{
		DeQueue(&dummy, pq);
	}
}

// �ֲ�����

static void CopyToNode(Item item, Node * pn)
{
	pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}