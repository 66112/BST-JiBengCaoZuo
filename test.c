#include "BSTree.h"
void test()
{
	BSTreeNode* tree=NULL;
	InsertNodeR(&tree, "sort", "����");
	InsertNodeR(&tree, "zoo", "����԰");
	InsertNodeR(&tree, "apple", "ƻ��");
	InsertNodeR(&tree, "search", "����");
	InsertNodeR(&tree, "aa", "����");
	InsertNodeR(&tree, "return", "����");
	RemoveNodeR(&tree, "apple");
}

int main()
{
	test();
	return 0;
}