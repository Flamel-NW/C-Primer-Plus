//《C Primer Plus》p631 17.12.8
// 17.12.8_tree.h -- 二叉查找树
//						树中不允许有重复的项

#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

// 根据具体情况重新定义 Item
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
	struct trnode * left;		// 指向左分支的指针
	struct trnode * right;		// 指向右分支的指针
} Trnode;

typedef struct tree
{
	Trnode * root;				// 指向根节点的指针
	int size;					// 树的项数
} Tree;

// 函数原型

// 操作：		把树初始化为空
// 前提条件：	ptree 指向一个树
// 后置条件：	树被初始化为空
void InitializeTree(Tree * ptree);

// 操作：		确定树是否为空
// 前提条件：	ptree 指向一个树
// 后置条件：	如果树为空，该函数返回 true；
//				否则，返回 false
bool TreeIsEmpty(const Tree * ptree);

// 操作：		确定树是否为满
// 前提条件：	ptree 指向一个树
// 后置条件：	如果树已满，该函数返回 true；
//				否则，返回 false
bool TreeIsFull(const Tree * ptree);

// 操作：		确定树的项数
// 前提条件：	ptree 指向一个树
// 后置条件：	返回树的项数
int TreeItemCount(const Tree * ptree);

// 操作：		在树中添加一个项
// 前提条件：	pi 是待添加项的地址
//					ptree 指向一个已初始化的树
// 后置条件：	如果在树中找到指定项，该函数返回 true
//					否则，返回 false
bool AddItem(const Item * pi, Tree * ptree);

// 操作：		从树中查找一个项
// 前提条件：	pi 指向一个项
//					ptree 指向一个已初始化的树
// 后置条件：	如果在树中找到指定项，该函数返回 true
//					否则，返回 false
bool InTree(const Item * pi, const Tree * ptree);

// 操作：		从树中删除一个项
// 前提条件：	pi 指向一个项
//					ptree 指向一个已初始化的树
// 后置条件：	如果从树中成功删除一个项，该函数返回 true
//					否则，返回 false
bool DeleteItem(const Item * pi, Tree * ptree);

// 操作：		把函数应用于树中的每一项
// 前提条件：	ptree 指向一个树
//					pfun 指向一个函数
//					该函数接受一个 Item 类型的参数，并无返回值
//	后置条件：	pfun 指向的这个函数为树中的每一项执行一次
void Traverse(const Tree * ptree, void(*pfun) (Item item));

// 操作：		删除树中的所有内容
// 前提条件：	ptree 指向一个已初始化的树
// 后置条件：	树为空
void DeleteAll(Tree * ptree);

// 根据具体情况定义的新函数
// 操作：		打印一个项中所有的宠物种类名称
// 前提条件：	pi 指向一个项
//					ptree 指向一个已初始化的树
// 后置条件：	如果从树中成功打印一个项，该函数返回 true
//					否则，返回 false
bool PrintItem(const Item * item, const Tree * ptree);

#endif
