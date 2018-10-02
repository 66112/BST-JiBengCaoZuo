#include "BSTree.h"
BSTreeNode* BuyNode(KeyDataType key, ValueDataType value)
{
	BSTreeNode* newNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	newNode->_left = NULL;
	newNode->_right = NULL;
	newNode->key = (KeyDataType)malloc(strlen(key) + 1);
	strcpy(newNode->key, key);
	newNode->value = (ValueDataType)malloc(strlen(value) + 1);
	strcpy(newNode->value, value);
	return newNode;
}
int InsertNodeR(BSTreeNode** tree, KeyDataType key, ValueDataType value)
{
	assert(tree);
	BSTreeNode* root = *tree;
	if (*tree == NULL)
	{
		*tree = BuyNode(key, value);
		return 1;
	}
	else
	{
		if (strcmp(root->key, key) > 0)
		{
			return InsertNodeR(&(root->_left), key, value);
		}
		else if (strcmp(root->key, key) < 0)
		{
			return InsertNodeR(&(root->_right), key, value);
		}
		else
		{
			printf("已有该元素，插入失败！\n");
			return 0;
		}
	}
}
int RemoveNodeR(BSTreeNode** tree, KeyDataType key)
{
	if (*tree == NULL)
		return 0;
	else
	{
		BSTreeNode* del = FindNode(*tree, key);
		if (del == NULL)
		{
			printf("删除失败！\n");
			return 0;
		}
		if (del->_left == NULL)
		{
			del = del->_right;				//del就相当于父亲节点指向del的指针
			free(del);
			del = NULL;
			printf("删除成功！\n");
			return 1;
		}
		else if (del->_right == NULL)
		{
			del = del->_left;
			free(del);
			del = NULL;
			printf("删除成功！\n");
			return 1;
		}
		else
		{
			BSTreeNode* replace = del->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}
			strcpy(del->key, replace->key);           //replace为右树的最小值
			strcpy(del->value, replace->value);
			return RemoveNodeR(&(del->_right), replace->key);    //转化为删除右树的替代节点的子问题
		}
	}
}

BSTreeNode* FindNode(BSTreeNode* tree, KeyDataType key)
{
	while (tree)
	{
		if (strcmp(tree->key, key) > 0)
		{
			tree = tree->_left;
		}
		else if (strcmp(tree->key, key) < 0)
		{
			tree = tree->_right;
		}
		else
		{
			printf("找到了!\n%s:%s\n",tree->key,tree->value);
			return tree;
		}
	}
	printf("没找到！\n");
	return NULL;
}
