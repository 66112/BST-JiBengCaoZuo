#include "BSTree.h"
void test()
{
	BSTreeNode* tree=NULL;
	InsertNodeR(&tree, "sort", "排序");
	InsertNodeR(&tree, "zoo", "动物园");
	InsertNodeR(&tree, "apple", "苹果");
	InsertNodeR(&tree, "search", "查找");
	InsertNodeR(&tree, "aa", "啊啊");
	InsertNodeR(&tree, "return", "返回");
	RemoveNodeR(&tree, "apple");
}

int main()
{
	test();
	return 0;
}