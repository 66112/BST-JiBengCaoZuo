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
			printf("���и�Ԫ�أ�����ʧ�ܣ�\n");
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
			printf("ɾ��ʧ�ܣ�\n");
			return 0;
		}
		if (del->_left == NULL)
		{
			del = del->_right;				//del���൱�ڸ��׽ڵ�ָ��del��ָ��
			free(del);
			del = NULL;
			printf("ɾ���ɹ���\n");
			return 1;
		}
		else if (del->_right == NULL)
		{
			del = del->_left;
			free(del);
			del = NULL;
			printf("ɾ���ɹ���\n");
			return 1;
		}
		else
		{
			BSTreeNode* replace = del->_right;
			while (replace->_left)
			{
				replace = replace->_left;
			}
			strcpy(del->key, replace->key);           //replaceΪ��������Сֵ
			strcpy(del->value, replace->value);
			return RemoveNodeR(&(del->_right), replace->key);    //ת��Ϊɾ������������ڵ��������
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
			printf("�ҵ���!\n%s:%s\n",tree->key,tree->value);
			return tree;
		}
	}
	printf("û�ҵ���\n");
	return NULL;
}
