/*	File: cas4-35ThreadTree.c
	【例4-35】顺序存储穿线树	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  M  50
#define  ABS(X)	((X) > 0 ? (X) : (-X))
#define TREE struct tree
TREE
{
	int key;
	int left, right;
};
TREE  Tree[M];
int n=0;		/* 结点数n<=M		*/

int getPre(TREE *th, int i)
{
	if(i<1 || i>n) 			/* 非法地址 */
		exit(0);
	if((i = th[i].left) > 0) 		/* 有左子 */
		while(th[i].right > 0) 	/* 有右子 */
			i = th[i].right;
	return(ABS(i));
}
int getSuc(TREE *th, int i)
{ 
	if(i<1 || i>n) 				/* 非法地址 */
		exit(0);
	if ((i=th[i].right)>0)		/* 有右子 */
		while(th[i].left>0) 	/* 有左子 */
			i = th[i].left;
	return(ABS(i));
}
int getFirst(TREE * th)
{
	int i;
	if((i=th[0].key) == 0)  /* 空树 */
		return(i);
	while(th[i].left != 0 ) /* 有左子 */
		i = th[i].left;
	return(i);
}
void  symOrderT(TREE * th)
{
	int p;
	/* 求中序始结点		*/
	if((p = getFirst(th)) == 0)
		exit(0);
	do
		printf("%d ", th[p].key);
	/* 求中序后件 */
	while(p = getSuc(th, p)) ;
	printf("\n");
}
void preOrder(TREE *tree, int root)	/* 前序遍历函数	*/
{
	if(root <= 0)
		return;
	printf("%d ", tree[root].key);
	preOrder(tree, tree[root].left);
	preOrder(tree, tree[root].right);
}
void symOrder(TREE *tree, int root)	/* 中序遍历函数	*/
{
	if(root <= 0)
		return;
	symOrder(tree, tree[root].left);
	printf("%d ", tree[root].key);
	symOrder(tree, tree[root].right);
}
void postOrder(TREE *tree, int root)	/* 后序遍历函数	*/
{
	if(root <= 0)
		return;
	postOrder(tree, tree[root].left);
	postOrder(tree, tree[root].right);
	printf("%d ", tree[root].key);
}
main()
{
	int  key, left, right;
	FILE *fp;
	char filename[M];
	printf("输入哪个文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	Tree[n++].key = 1;
	while(fscanf(fp, "%d%d%d", &key, &left, &right) == 3)
	{
		Tree[n].key = key;
		Tree[n].left = left;
		Tree[n].right = right;
		n++;
	}
	printf("#### 前序遍历 ####\n");
	preOrder(Tree, 1);
	printf("\n");
	printf("#### 后序遍历 ####\n");
	postOrder(Tree, 1);
	printf("\n");
	printf("#### 中序遍历 ####\n");
	symOrder(Tree, 1);
	printf("\n");
	printf("#### 穿线中序遍历 ####\n");
	symOrderT(Tree);
	system("pause");
}
/*
输入哪个文件: ThTree1.txt
#### 前序遍历 ####
10 20 60 30 80 50 40 70
#### 后序遍历 ####
30 80 60 20 70 40 50 10
#### 中序遍历 ####
20 30 60 80 10 40 70 50
#### 穿线中序遍历 ####
20 30 60 80 10 40 70 50

输入哪个文件: ThTree2.txt
#### 前序遍历 ####
50 19 15 35 20 55 52 53 98 88
#### 后序遍历 ####
15 20 35 19 53 52 88 98 55 50
#### 中序遍历 ####
15 19 20 35 50 52 53 55 88 98
#### 穿线中序遍历 ####
15 19 20 35 50 52 53 55 88 98
*/
