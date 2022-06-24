/*	File: cas4-35ThreadTree.c
	����4-35��˳��洢������	*/

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
int n=0;		/* �����n<=M		*/

int getPre(TREE *th, int i)
{
	if(i<1 || i>n) 			/* �Ƿ���ַ */
		exit(0);
	if((i = th[i].left) > 0) 		/* ������ */
		while(th[i].right > 0) 	/* ������ */
			i = th[i].right;
	return(ABS(i));
}
int getSuc(TREE *th, int i)
{ 
	if(i<1 || i>n) 				/* �Ƿ���ַ */
		exit(0);
	if ((i=th[i].right)>0)		/* ������ */
		while(th[i].left>0) 	/* ������ */
			i = th[i].left;
	return(ABS(i));
}
int getFirst(TREE * th)
{
	int i;
	if((i=th[0].key) == 0)  /* ���� */
		return(i);
	while(th[i].left != 0 ) /* ������ */
		i = th[i].left;
	return(i);
}
void  symOrderT(TREE * th)
{
	int p;
	/* ������ʼ���		*/
	if((p = getFirst(th)) == 0)
		exit(0);
	do
		printf("%d ", th[p].key);
	/* �������� */
	while(p = getSuc(th, p)) ;
	printf("\n");
}
void preOrder(TREE *tree, int root)	/* ǰ���������	*/
{
	if(root <= 0)
		return;
	printf("%d ", tree[root].key);
	preOrder(tree, tree[root].left);
	preOrder(tree, tree[root].right);
}
void symOrder(TREE *tree, int root)	/* �����������	*/
{
	if(root <= 0)
		return;
	symOrder(tree, tree[root].left);
	printf("%d ", tree[root].key);
	symOrder(tree, tree[root].right);
}
void postOrder(TREE *tree, int root)	/* �����������	*/
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
	printf("�����ĸ��ļ�: ");
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
	printf("#### ǰ����� ####\n");
	preOrder(Tree, 1);
	printf("\n");
	printf("#### ������� ####\n");
	postOrder(Tree, 1);
	printf("\n");
	printf("#### ������� ####\n");
	symOrder(Tree, 1);
	printf("\n");
	printf("#### ����������� ####\n");
	symOrderT(Tree);
	system("pause");
}
/*
�����ĸ��ļ�: ThTree1.txt
#### ǰ����� ####
10 20 60 30 80 50 40 70
#### ������� ####
30 80 60 20 70 40 50 10
#### ������� ####
20 30 60 80 10 40 70 50
#### ����������� ####
20 30 60 80 10 40 70 50

�����ĸ��ļ�: ThTree2.txt
#### ǰ����� ####
50 19 15 35 20 55 52 53 98 88
#### ������� ####
15 20 35 19 53 52 88 98 55 50
#### ������� ####
15 19 20 35 50 52 53 55 88 98
#### ����������� ####
15 19 20 35 50 52 53 55 88 98
*/
