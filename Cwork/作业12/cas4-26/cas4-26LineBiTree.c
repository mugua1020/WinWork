/*	File: cas4-26LineBiTree.c
	【例4-26】顺序存储二叉树	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  M  50
#define BITREE struct bitree
BITREE
{
	char key[10];
	int left, right;
};
BITREE  Tree[M];
int n=0;		/* 结点数n<=M		*/
void preOrder(BITREE *tree, int root)	/* 前序遍历函数	*/
{
	if(root < 0)
		return;
	printf("%s ", tree[root].key);
	preOrder(tree, tree[root].left);
	preOrder(tree, tree[root].right);
}
void symOrder(BITREE *tree, int root)	/* 中序遍历函数	*/
{
	if(root < 0)
		return;
	symOrder(tree, tree[root].left);
	printf("%s ", tree[root].key);
	symOrder(tree, tree[root].right);
}
void postOrder(BITREE *tree, int root)	/* 后序遍历函数	*/
{
	if(root < 0)
		return;
	postOrder(tree, tree[root].left);
	postOrder(tree, tree[root].right);
	printf("%s ", tree[root].key);
}
main()
{
	int  left, right;
	char str[10];
	FILE *fp;
	char filename[M];
	printf("输入哪个文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	while(fscanf(fp, "%s%d%d", str, &left, &right) == 3)
	{
		strcpy(Tree[n].key, str);
		Tree[n].left = left;
		Tree[n].right = right;
		n++;
	}
	printf("#### 前序遍历 ####\n");
	preOrder(Tree, 0);
	printf("\n");
	printf("#### 中序遍历 ####\n");
	symOrder(Tree, 0);
	printf("\n");
	printf("#### 后序遍历 ####\n");
	postOrder(Tree, 0);
	printf("\n");
	system("pause");
}
/*
输入哪个文件: BiTree1.txt
#### 前序遍历 ####
A B D G H C E F
#### 中序遍历 ####
B G D H A E F C
#### 后序遍历 ####
G H D B F E C A

输入哪个文件: BiTree2.txt
#### 前序遍历 ####
35 21 15 13 17 23 27 25 38 36
#### 中序遍历 ####
13 15 17 21 23 25 27 35 36 38
#### 后序遍历 ####
13 17 15 25 27 23 21 36 38 35

输入哪个文件: BiTree3.txt
#### 前序遍历 ####
81 53 46 49 67 55 58 73 77 87 83 90
#### 中序遍历 ####
46 49 53 55 58 67 73 77 81 83 87 90
#### 后序遍历 ####
49 46 58 55 77 73 67 53 83 90 87 81
*/
