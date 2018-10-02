#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

typedef char* KeyDataType;
typedef char* ValueDataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	KeyDataType key;
	ValueDataType value;
}BSTreeNode;

BSTreeNode* BuyNode(KeyDataType key, ValueDataType value);
int InsertNodeR(BSTreeNode** tree, KeyDataType key, ValueDataType value);
int RemoveNodeR(BSTreeNode** tree, KeyDataType key);
BSTreeNode* FindNode(BSTreeNode* tree, KeyDataType key);
