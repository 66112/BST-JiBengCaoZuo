//#include "BinarySearchTree.h"
//BSTNode* BSTBuyNode(BSTDataType x)
//{
//	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
//	newNode->_data = x;
//	newNode->_left = NULL;
//	newNode->_right = NULL;
//	return newNode;
//}
//int InsertBSTNode(BSTNode** root, BSTDataType x)
//{
//	if (*root == NULL)
//	{
//		*root = BSTBuyNode(x);
//		return 1;
//	}
//	BSTNode* parent = NULL;
//	BSTNode* cur = *root;
//	while (cur)
//	{
//		if (cur->_data > x)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else if (cur->_data < x)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else
//		{
//			printf("���ܲ�������ȵ�Ԫ�أ�\n");
//			return 0;
//		}
//	}
//	if (parent->_data > x)
//	{
//		parent->_left = BSTBuyNode(x);
//		return 1;
//	}
//	else
//	{
//		parent->_right = BSTBuyNode(x);
//		return 1;
//	}
//}
//BSTNode* FindBSTNode(BSTNode* tree, BSTDataType x)
//{
//	assert(tree);
//	BSTNode* cur = tree;
//	while (cur)
//	{
//		if (cur->_data > x)
//		{
//			cur = cur->_left;
//		}
//		else if (cur->_data < x)
//		{
//			cur = cur->_right;
//		}
//		else
//		{
//			return cur;
//		}
//	}
//	return NULL;
//}
//int RemoveBSTNode(BSTNode** root, BSTDataType x)
//{
//	assert(*root);
//	BSTNode* parent = NULL;
//	BSTNode* cur = *root;
//	BSTNode* _right;
//	while (cur)
//	{
//		if (cur->_data > x)
//		{
//			parent = cur;
//			cur = cur->_left;
//		}
//		else if (cur->_data < x)
//		{
//			parent = cur;
//			cur = cur->_right;
//		}
//		else
//		{
//			if (cur->_right == NULL)
//			{
//				if (parent->_left == cur)
//				{
//					free(cur);
//					cur = NULL;
//					parent->_left = NULL;
//				}
//				else if (parent->_right==cur)
//				{
//					free(cur);
//					cur = NULL;
//					parent->_right = NULL;
//				}
//				return 1;
//			}
//			if (cur->_left == NULL)    //��գ��Ҳ���
//			{
//				if (parent == NULL)     //ͷ�ڵ�
//				{
//					*root = cur->_right;
//					free(cur);
//					cur = NULL;
//				}
//				else
//				{
//					parent->_right = cur->_right;
//					free(cur);
//					cur = NULL;
//				}
//				return 1;
//			}
//
//			if (cur->_left != NULL&&cur->_right != NULL)
//			{
//				parent = cur;
//				_right = cur->_right;    //���Һ���������Сֵ������ýڵ�
//				while (_right->_left)
//				{
//					parent = _right;
//					_right = _right->_left;
//				}
//				cur->_data = _right->_data;
//				if (_right->_left == NULL&&_right->_right == NULL)
//				{
//					if (parent->_left == _right)
//					{
//						free(_right);
//						cur = NULL;
//						parent->_left = NULL;
//					}
//					else if (parent->_right == _right)
//					{
//						free(_right);
//						cur = NULL;
//						parent->_right = NULL;
//					}
//					return 1;
//				}
//				else
//				{
//					parent->_right = _right->_right;
//					free(_right);
//					_right = NULL;
//				}
//			}	     				
//		}
//	}
//	return 0;
//}
//
//void BSTreeINoder(BSTNode* tree)
//{
//	if (tree == NULL)
//		return;
//	else
//	{
//		BSTreeINoder(tree->_left);
//		printf("%d ", tree->_data);
//		BSTreeINoder(tree->_right);
//	}
//}
//
//void DestoryBST(BSTNode* tree)
//{
//	if (tree == NULL)
//	{
//		return;
//	}
//	else
//	{
//		DestoryBST(tree->_left);
//		DestoryBST(tree->_right);
//		free(tree);
//		tree = NULL;
//	}
//}
//
//int InsertBSTNodeR(BSTNode** root, BSTDataType x)
//{
//	if (*root == NULL)
//	{
//		*root = BSTBuyNode(x);
//		return 1;
//	}
//	else
//	{
//		if ((*root)->_data > x)
//		{
//			return InsertBSTNodeR(&(*root)->_left, x);
//		}
//		else if ((*root)->_data < x)
//		{
//			return InsertBSTNodeR(&(*root)->_right, x);
//		}
//		else
//		{
//			printf("����ʧ�ܣ�\n");
//			return 0;
//		}
//	}
//}
//
//BSTNode* FindBSTNodeR(BSTNode* tree, BSTDataType x)
//{
//	if (tree == NULL)
//	{
//		printf("û�ҵ���\n");
//		return NULL;
//	}
//	else
//	{
//		if (tree->_data > x)
//		{
//			return FindBSTNodeR(tree->_left, x);
//		}
//		else if (tree->_data < x)
//		{
//			return FindBSTNodeR(tree->_right, x);
//		}
//		else
//		{
//			printf("�ҵ��ˣ�\n");
//			return tree;
//		}
//	}
//}
//
//int RemoveBSTNodeR(BSTNode** root, BSTDataType x)
//{
//	if (*root == NULL)
//	{
//		printf("ɾ��ʧ�ܣ�\n");
//		return 0;
//	}
//	else
//	{
//		if ((*root)->_data > x)
//		{
//			return RemoveBSTNodeR(&(*root)->_left, x);
//		}
//		else if ((*root)->_data < x)
//		{
//			return RemoveBSTNodeR(&(*root)->_right, x);
//		}
//		else
//		{
//			BSTNode* del = *root;
//			if ((*root)->_left == NULL)              //*rootָ��ɾ�ڵ�
//			{
//				*root = (*root)->_right;
//				free(del);
//				del = NULL;
//				return 1;
//			}
//			else if ((*root)->_right == NULL)
//			{
//				*root = (*root)->_left;
//				free(del);
//				del = NULL;
//				return 1;
//			}
//			else
//			{
//				BSTNode* replace;
//				replace = (*root)->_right;
//				while (replace->_left)
//				{
//					replace = replace->_left;
//				}
//				(*root)->_data = replace->_data;
//				return RemoveBSTNodeR(&(*root)->_right, replace->_data);
//			}
//		}
//	}
//}
