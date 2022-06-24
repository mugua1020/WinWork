/*	File: cas4-27OnePtrBiTree.c
	【例4-27】顺序存储一个指针场的二叉树	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  M  100
#define ABS(x)   ((x>0) ? (x) : (-x))
#define BITREE struct bitree
BITREE
{
	char key[10];
	int ptr;
};
BITREE  Tree[M];
int n=0;		/* 结点数n<=M		*/
int leftSub(BITREE *tree, int i)	/* 求左子结点	*/
{
	if(tree[i].ptr > 0 || tree[i].ptr == M)
		return(i+1);
	return(-M);
}
int rightSub(BITREE *tree, int i)	/* 求右子结点	*/
{
	if(ABS(tree[i].ptr) != M)
		return(ABS(tree[i].ptr));
	return(-M);
}
void preOrder(BITREE *tree)	/* 前序遍历函数	*/
{
	int i;
	for(i=0; i<n; i++)
		printf("%s ", tree[i].key);
	printf("\n");
}
void symOrder(BITREE *tree, int root)	/* 中序遍历函数	*/
{
	if(root < 0)
		return;
	symOrder(tree, leftSub(tree, root));
	printf("%s ", tree[root].key);
	symOrder(tree, rightSub(tree, root));
}
void postOrder(BITREE *tree, int root)	/* 后序遍历函数	*/
{
	if(root < 0)
		return;
	postOrder(tree, leftSub(tree, root));
	postOrder(tree, rightSub(tree, root));
	printf("%s ", tree[root].key);
}
main()
{
	int  ptr;
	char str[10];
	FILE *fp;
	char filename[60];
	printf("输入哪个文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	while(fscanf(fp, "%s%d", str, &ptr) == 2)
	{
		strcpy(Tree[n].key, str);
		Tree[n].ptr = ptr;
		n++;
	}
	printf("#### 前序遍历 ####\n");
	preOrder(Tree);
	printf("#### 中序遍历 ####\n");
	symOrder(Tree, 0);
	printf("\n");
	printf("#### 后序遍历 ####\n");
	postOrder(Tree, 0);
	printf("\n");
	system("pause");
}
/*
输入哪个文件: OnePtr1.txt
#### 前序遍历 ####
A B D G H C E F
#### 中序遍历 ####
B G D H A E F C
#### 后序遍历 ####
G H D B F E C A

输入哪个文件: OnePtr2.txt
#### 前序遍历 ####
35 21 15 13 17 23 27 25 38 36
#### 中序遍历 ####
13 15 17 21 23 25 27 35 36 38
#### 后序遍历 ####
13 17 15 25 27 23 21 36 38 35

输入哪个文件: OnePtr3.txt
#### 前序遍历 ####
81 53 46 49 67 55 58 73 77 87 83 90
#### 中序遍历 ####
46 49 53 55 58 67 73 77 81 83 87 90
#### 后序遍历 ####
49 46 58 55 77 73 67 53 83 90 87 81
*/
