//��C Primer Plus��p631 17.12.8
// 17.12.8_tree.h -- ���������
//						���в��������ظ�����

#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

// ���ݾ���������¶��� Item
#define SLEN 20
#define MAX 10
typedef struct item
{
	char petname[SLEN];
	char petkind[MAX][SLEN];
	int nums;
} Item;

#define MAXITEMS 100

typedef struct trnode
{
	Item item;
	struct trnode * left;		// ָ�����֧��ָ��
	struct trnode * right;		// ָ���ҷ�֧��ָ��
} Trnode;

typedef struct tree
{
	Trnode * root;				// ָ����ڵ��ָ��
	int size;					// ��������
} Tree;

// ����ԭ��

// ������		������ʼ��Ϊ��
// ǰ��������	ptree ָ��һ����
// ����������	������ʼ��Ϊ��
void InitializeTree(Tree * ptree);

// ������		ȷ�����Ƿ�Ϊ��
// ǰ��������	ptree ָ��һ����
// ����������	�����Ϊ�գ��ú������� true��
//				���򣬷��� false
bool TreeIsEmpty(const Tree * ptree);

// ������		ȷ�����Ƿ�Ϊ��
// ǰ��������	ptree ָ��һ����
// ����������	������������ú������� true��
//				���򣬷��� false
bool TreeIsFull(const Tree * ptree);

// ������		ȷ����������
// ǰ��������	ptree ָ��һ����
// ����������	������������
int TreeItemCount(const Tree * ptree);

// ������		���������һ����
// ǰ��������	pi �Ǵ������ĵ�ַ
//					ptree ָ��һ���ѳ�ʼ������
// ����������	����������ҵ�ָ����ú������� true
//					���򣬷��� false
bool AddItem(const Item * pi, Tree * ptree);

// ������		�����в���һ����
// ǰ��������	pi ָ��һ����
//					ptree ָ��һ���ѳ�ʼ������
// ����������	����������ҵ�ָ����ú������� true
//					���򣬷��� false
bool InTree(const Item * pi, const Tree * ptree);

// ������		������ɾ��һ����
// ǰ��������	pi ָ��һ����
//					ptree ָ��һ���ѳ�ʼ������
// ����������	��������гɹ�ɾ��һ����ú������� true
//					���򣬷��� false
bool DeleteItem(const Item * pi, Tree * ptree);

// ������		�Ѻ���Ӧ�������е�ÿһ��
// ǰ��������	ptree ָ��һ����
//					pfun ָ��һ������
//					�ú�������һ�� Item ���͵Ĳ��������޷���ֵ
//	����������	pfun ָ����������Ϊ���е�ÿһ��ִ��һ��
void Traverse(const Tree * ptree, void(*pfun) (Item item));

// ������		ɾ�����е���������
// ǰ��������	ptree ָ��һ���ѳ�ʼ������
// ����������	��Ϊ��
void DeleteAll(Tree * ptree);

// ���ݾ������������º���
// ������		��ӡһ���������еĳ�����������
// ǰ��������	pi ָ��һ����
//					ptree ָ��һ���ѳ�ʼ������
// ����������	��������гɹ���ӡһ����ú������� true
//					���򣬷��� false
bool PrintItem(const Item * item, const Tree * ptree);

#endif
