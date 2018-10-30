#include "BinarySearchTree.h"

//void testBSTree()
//{
//	BSTNode* tree = NULL;
//	InsertBSTNode(&tree, 5);
//	InsertBSTNode(&tree, 3);
//	InsertBSTNode(&tree, 7);
//	InsertBSTNode(&tree, 1);
//	InsertBSTNode(&tree, 4);
//	InsertBSTNode(&tree, 6);
//	InsertBSTNode(&tree, 8);
//	InsertBSTNode(&tree, 0);
//	InsertBSTNode(&tree, 2);
//	InsertBSTNode(&tree, 9);
//	BSTNode* node = FindBSTNode(tree,8);
//	if (node == NULL)
//	{
//		printf("Ã»ÕÒµ½£¡\n");
//	}
//	//printf("%d ", node->_data);
//	BSTreeINoder(tree);
//	DestoryBST(tree);
//}
//void testBSTreeR()
//{
//	BSTNode* tree = NULL;
//	InsertBSTNodeR(&tree, 5);
//	InsertBSTNodeR(&tree, 3);
//	InsertBSTNodeR(&tree, 7);
//	InsertBSTNodeR(&tree, 1);
//	InsertBSTNodeR(&tree, 4);
//	InsertBSTNodeR(&tree, 6);
//	InsertBSTNodeR(&tree, 8);
//	InsertBSTNodeR(&tree, 0);
//	InsertBSTNodeR(&tree, 2);
//	InsertBSTNodeR(&tree, 9);
//	//FindBSTNodeR(tree, 8);
//	//FindBSTNodeR(tree, 10);
//	RemoveBSTNodeR(&tree, 5);
//	RemoveBSTNodeR(&tree, 1);
//	RemoveBSTNodeR(&tree, 2);
//	RemoveBSTNodeR(&tree, 3);
//
//	BSTreeINoder(tree);
//	DestoryBST(tree);
//}

void testKeyValue()
{
	BSTNode* tree=NULL;
	char arr[10];
	while (1)
	{
		scanf("%s", arr);
		if (strcmp(arr, "exit") == 0)
			break;
		BSTNode* node=FindBSTNode(tree, arr);
		if (node)
		{
			node->_value++;
		}
		else
		{
			InsertBSTNode(&tree, arr, 1);
		}
	}
	BSTreeINoder(tree);
}
int main()
{
	testKeyValue();
	//testBSTreeR();
	//testBSTree();
	return 0;
}