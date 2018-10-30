//#pragma once
//#include <stdio.h>
//#include <assert.h>
//#include <malloc.h>
//
//typedef int BSTDataType;
//typedef struct BSTNode
//{
//	struct BSTNode* _left;
//	struct BSTNode* _right;
//	BSTDataType _data;
//}BSTNode;
//
//int InsertBSTNode(BSTNode** root, BSTDataType x);
//BSTNode* FindBSTNode(BSTNode* tree, BSTDataType x);
//int RemoveBSTNode(BSTNode** root, BSTDataType x);
//void BSTreeINoder(BSTNode* tree);
//void DestoryBST(BSTNode* tree);
//
//int InsertBSTNodeR(BSTNode** root, BSTDataType x);
//BSTNode* FindBSTNodeR(BSTNode* tree, BSTDataType x);
//int RemoveBSTNodeR(BSTNode** root, BSTDataType x);

////////////////////////////////////////////////////////////////
//key/value³¡¾°
#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef char* BSTkeyDataType;
typedef int BSTvalueDataType;
typedef struct BSTNode
{
	struct BSTNode* _left;
	struct BSTNode* _right;
	BSTkeyDataType _key;
	BSTvalueDataType _value;
}BSTNode;

int InsertBSTNode(BSTNode** root, BSTkeyDataType key,BSTvalueDataType value);
BSTNode* FindBSTNode(BSTNode* tree, BSTkeyDataType key);
int RemoveBSTNode(BSTNode** root, BSTkeyDataType key);
void BSTreeINoder(BSTNode* tree);
void DestoryBST(BSTNode* tree);

