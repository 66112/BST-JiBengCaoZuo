#include "BinarySearchTree.h"
BSTNode* BSTBuyNode(BSTkeyDataType key,BSTvalueDataType value)
{
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	newNode->_key = (BSTkeyDataType)malloc(strlen(key)+1);
	strcpy(newNode->_key, key);
	newNode->_value = value;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}
int InsertBSTNode(BSTNode** root, BSTkeyDataType key,BSTvalueDataType value)
{
	if (*root == NULL)
	{
		*root = BSTBuyNode(key,value);
		return 1;
	}
	BSTNode* parent = NULL;
	BSTNode* cur = *root;
	while (cur)
	{
		if (strcmp(cur->_key,key)>0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key)<0)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			printf("不能插入与相等的元素！\n");
			return 0;
		}
	}
	if (strcmp(parent->_key, key)>0)
	{
		parent->_left = BSTBuyNode(key,value);
		return 1;
	}
	else
	{
		parent->_right = BSTBuyNode(key,value);
		return 1;
	}
}
BSTNode* FindBSTNode(BSTNode* tree, BSTkeyDataType key)
{
	BSTNode* cur = tree;
	while (cur)
	{
		if (strcmp(cur->_key, key)>0)
		{
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key)<0)
		{
			cur = cur->_right;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}
int RemoveBSTNode(BSTNode** root, BSTkeyDataType key)
{
	assert(*root);
	BSTNode* parent = NULL;
	BSTNode* cur = *root;
	BSTNode* _right;
	while (cur)
	{
		if (strcmp(cur->_key, key)>0)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (strcmp(cur->_key, key)<0)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			if (cur->_right == NULL)
			{
				if (parent->_left == cur)
				{
					free(cur);
					cur = NULL;
					parent->_left = NULL;
				}
				else if (parent->_right == cur)
				{
					free(cur);
					cur = NULL;
					parent->_right = NULL;
				}
				return 1;
			}
			if (cur->_left == NULL)    //左空，右不空
			{
				if (parent == NULL)     //头节点
				{
					*root = cur->_right;
					free(cur);
					cur = NULL;
				}
				else
				{
					parent->_right = cur->_right;
					free(cur);
					cur = NULL;
				}
				return 1;
			}

			if (cur->_left != NULL&&cur->_right != NULL)
			{
				parent = cur;
				_right = cur->_right;    //在右孩子中找最小值，接替该节点
				while (_right->_left)
				{
					parent = _right;
					_right = _right->_left;
				}
				cur->_key = _right->_key;
				if (_right->_left == NULL&&_right->_right == NULL)
				{
					if (parent->_left == _right)
					{
						free(_right);
						cur = NULL;
						parent->_left = NULL;
					}
					else if (parent->_right == _right)
					{
						free(_right);
						cur = NULL;
						parent->_right = NULL;
					}
					return 1;
				}
				else
				{
					parent->_right = _right->_right;
					free(_right);
					_right = NULL;
				}
			}
		}
	}
	return 0;
}

void BSTreeINoder(BSTNode* tree)
{
	if (tree == NULL)
		return;
	else
	{
		BSTreeINoder(tree->_left);
		printf("%s:%d\n", tree->_key,tree->_value);
		BSTreeINoder(tree->_right);
	}
}

void DestoryBST(BSTNode* tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		DestoryBST(tree->_left);
		DestoryBST(tree->_right);
		free(tree);
		tree = NULL;
	}
}

