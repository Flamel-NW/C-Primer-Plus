//��C Primer Plus��p631 17.12.8
// 17.12.8_tree.cpp -- ����֧�ֺ���

#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "17.12.8_tree.h"

// �ֲ���������
typedef struct pair
{
	Trnode * parent;
	Trnode * child;
} Pair;

// �ֲ�������ԭ��
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root, void(*pfun)(Item item));
static Pair SeekItem(const Item * pi, const Tree *);
static void DeleteNode(Trnode ** ptr);
static void DeleteAllNodes(Trnode * ptr);
int PetCount(const Item * pi, const Tree * ptree);

// ��������
void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TreeIsFull(const Tree * ptree)
{
	if (ptree->size == MAXITEMS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Trnode * new_node;
	Pair look;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;											// ��ǰ����
	}
	look = SeekItem(pi, ptree);
	if (look.child != NULL)
	{
		strcpy_s(look.child->item.petkind[look.child->item.nums]
			, *pi->petkind);
		look.child->item.nums++;
		return true;											// ��ǰ����
	}
	new_node = MakeNode(pi);									// ָ���½ڵ�
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn/'t create node\n");
		return false;											// ��ǰ����
	}
	// �ɹ�������һ���½ڵ�
	ptree->size++;

	if (ptree->root == NULL)									// ���1����Ϊ��
	{
		ptree->root = new_node;									// �½ڵ�Ϊ���ĸ��ڵ�
	}
	else														// ���2������Ϊ��
	{
		AddNode(new_node, ptree->root);							// ����������½ڵ�
	}

	return true;												// �ɹ�����
}

bool InTree(const Item * pi, const Tree * ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;

	look = SeekItem(pi, ptree);
	if (look.child == NULL)
	{
		return false;
	}

	if (look.parent == NULL)		// ɾ�����ڵ���
	{
		DeleteNode(&ptree->root);
	}
	else if (look.parent->left == look.child)
	{
		DeleteNode(&look.parent->left);
	}
	else
	{
		DeleteNode(&look.parent->right);
	}
	ptree->size--;

	return true;
}

void Traverse(const Tree * ptree, void(*pfun) (Item item))
{
	if (ptree != NULL)
	{
		InOrder(ptree->root, pfun);
	}
}

void DeleteAll(Tree * ptree)
{
	if (ptree != NULL)
	{
		DeleteAllNodes(ptree->root);
	}
	ptree->root = NULL;
	ptree->size = 0;
}

bool PrintItem(const Item * item, const Tree * ptree)
{
	Pair look;

	look = SeekItem(item, ptree);
	if (look.child == NULL)
	{
		return false;
	}

	int i;
	for (i = 0; i < look.child->item.nums; i++)
	{
		printf("%s the %s\n", look.child->item.petname, look.child->item.petkind[i]);
	}

	return true;
}

// �ֲ�����
static void InOrder(const Trnode * root, void(*pfun) (Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode * root)
{
	Trnode * pright;

	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode(Trnode * new_node, Trnode * root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)							// ������
		{
			root->left = new_node;						// �ѽڵ���ӵ��˴�
		}
		else
		{
			AddNode(new_node, root->right);				// �����������
		}
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
		{
			root->right = new_node;
		}
		else											// ���������ظ���
		{
			AddNode(new_node, root->right);
		}
	}
	else
	{
		fprintf(stderr, "location err in Addnode()\n");
		exit(EXIT_FAILURE);
	}
}

static bool ToLeft(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
	{
		return true;
	}
	else if (comp1 == 0 && strcmp(i1->petname, i2->petname) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static bool ToRight(const Item * i1, const Item * i2)
{
	int comp1;

	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
	{
		return true;
	}
	else if (comp1 == 0 && strcmp(i1->petname, i2->petname) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

static Trnode * MakeNode(const Item * pi)
{
	Trnode * new_node;

	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->item.nums = 1;
		new_node->left = NULL;
		new_node->right = NULL;
	}

	return new_node;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
	{
		return look;									// ��ǰ����
	}

	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else		// ���ǰ��������������㣬��ض�����ȵ����
		{
			break;	// look.child Ŀ����Ľڵ�
		}
	}

	return look;										// �ɹ�����
}

static void DeleteNode(Trnode ** ptr)
// ptr ��ָ��Ŀ��ڵ�ĸ��ڵ�ָ���Ա�ĵ�ַ
{
	Trnode * temp;

	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else	// ��ɾ���Ľڵ��������ӽڵ�
	{
		// �ҵ�����������������λ��
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
		{
			continue;
		}
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}