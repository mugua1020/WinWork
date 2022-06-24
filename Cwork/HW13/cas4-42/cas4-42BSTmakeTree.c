/* File: cas4-42BSTmakeTree.c
	【例4-42】二叉搜索树生成程序	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define BST struct bst
BST
{
	int key;
	BST *left, *right;
};
BST *Root=NULL;
void insertNode(BST *root, BST *node)
{
	if(node->key == root->key)
		return;
	else if(root->left != NULL && node->key < root->key)
		insertNode(root->left, node);
	else if(root->right != NULL && node->key > root->key)
		insertNode(root->right, node);
	else if(root->left == NULL && node->key < root->key)
	{
		node->left = root->left;
		root->left = node;
	}
	else if(root->right == NULL && node->key > root->key)
	{
		node->right = root->right;
		root->right = node;
	}
}
void symOrder(BST *node)
{
	if(node == NULL)
		return;
	symOrder(node->left);
	printf("%2d ", node->key);
	symOrder(node->right);
}
void preOrder(BST *node)
{
	if(node == NULL)
		return;
	printf("%2d ", node->key);
	preOrder(node->left);
	preOrder(node->right);
}
BST *newNode(int key)
{
	BST *node;
	if((node = (BST *)malloc(sizeof(BST))) == NULL)
		exit(0);
	node->key = key;
	node->left = node->right = NULL;
	return(node);
}
void main()
{
	int key;
	BST *node;
	FILE *fp;
	char filename[60];
	printf("BST结点文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	fscanf(fp, "%d", &key);
	Root = newNode(key);
	printf("Root=%d\n", Root->key);
	while(fscanf(fp, "%d", &key) == 1)
	{
		node= newNode(key);
		printf("node=%d\n", node->key);
		insertNode(Root, node);
	}
	printf("symOrder: ");
	symOrder(Root);
	printf("\n");
	printf("preOrder: ");
	preOrder(Root);
	printf("\n");
/*	if debug
*/
	system("pause");
}
/*
BST结点文件: BSTdata1.txt
Root=50
node=19
node=35
node=55
node=20
node=52
node=98
node=5
node=88
node=53
node=92
symOrder:  5 19 20 35 50 52 53 55 88 92 98
preOrder: 50 19  5 35 20 55 52 53 98 88 92

BST结点文件: BSTdata2.txt
Root=24
node=11
node=28
node=32
node=12
node=18
node=11
node=21
node=35
node=15
node=17
node=39
node=28
node=26
node=19
symOrder: 11 12 15 17 18 19 21 24 26 28 32 35 39
preOrder: 24 11 12 18 15 17 21 19 28 26 32 35 39

BST结点文件: BSTdata3.txt
node=17
node=32
node=12
node=19
node=39
node=21
node=26
node=11
node=35
node=32
node=18
node=28
node=11
node=15
symOrder: 11 12 15 17 18 19 21 24 26 28 32 35 39
preOrder: 24 17 12 11 15 19 18 21 32 26 28 39 35

BST结点文件: BSTdata4.txt
Root=40
node=35
node=81
node=21
node=38
node=44
node=87
node=15
node=23
node=36
node=53
node=83
node=13
node=17
node=27
node=49
node=67
node=25
node=46
node=55
node=73
node=58
node=77
symOrder: 13 15 17 21 23 25 27 35 36 38 40 44 46 49 53 55 58 67 73 77 81 83 87
preOrder: 40 35 21 15 13 17 23 27 25 38 36 81 44 53 49 46 67 55 58 73 77 87 83
*/
