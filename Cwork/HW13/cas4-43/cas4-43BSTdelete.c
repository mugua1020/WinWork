/* File: cas4-43BSTdelete.c
	【例4-43】二叉搜索树结点删除程序	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define BST struct bst
BST
{
	int key;
	BST *left, *right;
};

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
void prt(BST *Root)
{
	printf("symOrder: ");
	symOrder(Root);
	printf("\n");
	printf("preOrder: ");
	preOrder(Root);
	printf("\n");
}
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
		return;
	}
	else if(root->right == NULL && node->key > root->key)
	{
		node->right = root->right;
		root->right = node;
		return;
	}
}
BST * deleteLeft(BST *root, BST *node)
{
	BST *prev, *tmp;
	if(node->left == NULL)				/* 1L1	*/
		printf("1L1\n"), root->left = node->right;
	/* complete the following code		*/

	else if(node->left->right == NULL)	/* 2L2	*/
	{
		printf("2L2\n"), node->left->right = node->right;
		root->left = node->left;
	}
	else if(node->right == NULL)		/* 2L1	*/
		printf("2L1\n"), root->left = node->left;
	else if(node->right->left == NULL)	/* 1L2	*/
	{
		printf("1L2\n"), node->right->left = node->left;
		root->left = node->right;
	}
	else if(node->left->right != NULL)	/* 3L	*/
	{
		printf("3L\n"), prev = node->left;
		while(prev->right != NULL &&
			  prev->right->right != NULL)
			prev = prev->right;				/* 寻找node的中序前件	*/
		tmp = prev->right->left;			/* 保存中序前件的左子	*/
		prev->right->left = node->left;		/* 替代node的左右子		*/
		prev->right->right = node->right;
		root->left = prev->right;			/* 更新node				*/
		prev->right = tmp;					/* 指向保存的tmp		*/
	}
	
	
	
	/* --------------------------------	*/
	return(node);
}
BST * deleteRight(BST *root, BST *node)
{
	BST *prev, *tmp;
	if(node->left == NULL)				/* 1R1	*/
		printf("1R1\n"), root->right = node->right;
	else if(node->left->right == NULL)	/* 2R2	*/
	{
		printf("2R2\n"), node->left->right = node->right;
		root->right = node->left;
	}
	else if(node->right == NULL)		/* 2R1	*/
		printf("2R1\n"), root->right = node->left;
	else if(node->right->left == NULL)	/* 1R2	*/
	{
		// printf("2R2\n"), node->right->left = node->left;
		printf("1R2\n"), node->right->left = node->left;
		root->right = node->right;
	}
	else if(node->left->right != NULL)	/* 3R	*/
	{
		printf("3R\n"), prev = node->left;
		while(prev->right != NULL &&
			  prev->right->right != NULL)
			prev = prev->right;				/* 寻找node的中序前件	*/
		tmp = prev->right->left;			/* 保存中序前件的左子	*/
		prev->right->left = node->left;		/* 替代node的左右子		*/
		prev->right->right = node->right;
		root->right = prev->right;			/* 更新node				*/
		prev->right = tmp;					/* 指向保存的tmp		*/
	}
	return(node);
}
BST * searchBst(BST *root, BST *node, int key)
{
	if(node == NULL)
		return(NULL);
	else if(key == node->key)
	{
		printf("d:root=%d node=%d\n", root->key, node->key);
		if(root->left == node)
			return( deleteLeft(root, node) );
		if(root->right == node)
			return( deleteRight(root, node) );
	}
	else if(key < node->key)
	{
		printf("sL:key=%d node=%d\n", key, node->key);
		return( searchBst(node, node->left, key) );
	}
	else if(key > node->key)
	{
		printf("sR:key=%d node=%d\n", key, node->key);
		return( searchBst(node, node->right, key) );
	}
	return(NULL);
}



//gcc .\cas4-43BSTdelete.c -fexec-charset=gbk -o BSTdelete.exe
//样例似乎存在问题，这里进行了修正
void main()
{
	int key, mini=-1;
	BST *Root=NULL;
	BST *node;
	FILE *fp;
	char filename[60];
	printf("BST结点文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	fscanf(fp, "%d", &key);
	if((Root = (BST *)malloc(sizeof(BST))) == NULL)
		exit(0);
	Root->key = key;
	Root->left = Root->right = NULL;
	while(fscanf(fp, "%d", &key) == 1)
	{
		if((node = (BST *)malloc(sizeof(BST))) == NULL)
			exit(0);
		node->key = key;
		node->left = node->right = NULL;
		mini = MIN(mini, key);
		insertNode(Root, node);
	}
	prt(Root);
	if((node = (BST *)malloc(sizeof(BST))) == NULL)
		exit(0);
	node->left = NULL;
	node->right = Root;
	node->key = mini;
	Root = node;
	key = -1;
	while(key != 0)
	{
		printf("删除哪个结点: ");
		scanf("%d", &key);
		if( node = searchBst(Root, Root->right, key) )
			prt(Root->right);
		else
			printf("cannot found key: %d\n", key);
	}
	system("pause");
}
/*
BST结点文件: BSTdata4.txt
symOrder: 13 15 17 21 23 25 27 35 36 38 40 44 46 49 53 55 58 67 73 77 81 83 87
preOrder: 40 35 21 15 13 17 23 27 25 38 36 81 44 53 49 46 67 55 58 73 77 87 83

删除测试
第1批:  25 1L1   15 1L2   58 1R1   73 1R1   53 1R2
第2批:  55 1L1   49 2L1   21 2L2   27 2R1   67 2R2
第3批:  35 3L    81 3R
第4批:  40 3R Root
见输出文件：BSTout4-1.txt, BSTout4-2.txt, BSTout4-3.txt, BSTout4-4.txt

BST结点文件: BSTdata1.txt
symOrder:  5 19 20 35 50 52 53 55 88 92 98
preOrder: 50 19  5 35 20 55 52 53 98 88 92
*/
