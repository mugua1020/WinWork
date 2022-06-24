/*	File: cas4-27OnePtrBiTree.c
	����4-27��˳��洢һ��ָ�볡�Ķ�����	*/

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
int n=0;		/* �����n<=M		*/
int leftSub(BITREE *tree, int i)	/* �����ӽ��	*/
{
	if(tree[i].ptr > 0 || tree[i].ptr == M)
		return(i+1);
	return(-M);
}
int rightSub(BITREE *tree, int i)	/* �����ӽ��	*/
{
	if(ABS(tree[i].ptr) != M)
		return(ABS(tree[i].ptr));
	return(-M);
}
void preOrder(BITREE *tree)	/* ǰ���������	*/
{
	int i;
	for(i=0; i<n; i++)
		printf("%s ", tree[i].key);
	printf("\n");
}
void symOrder(BITREE *tree, int root)	/* �����������	*/
{
	if(root < 0)
		return;
	symOrder(tree, leftSub(tree, root));
	printf("%s ", tree[root].key);
	symOrder(tree, rightSub(tree, root));
}
void postOrder(BITREE *tree, int root)	/* �����������	*/
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
	printf("�����ĸ��ļ�: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	while(fscanf(fp, "%s%d", str, &ptr) == 2)
	{
		strcpy(Tree[n].key, str);
		Tree[n].ptr = ptr;
		n++;
	}
	printf("#### ǰ����� ####\n");
	preOrder(Tree);
	printf("#### ������� ####\n");
	symOrder(Tree, 0);
	printf("\n");
	printf("#### ������� ####\n");
	postOrder(Tree, 0);
	printf("\n");
	system("pause");
}
/*
�����ĸ��ļ�: OnePtr1.txt
#### ǰ����� ####
A B D G H C E F
#### ������� ####
B G D H A E F C
#### ������� ####
G H D B F E C A

�����ĸ��ļ�: OnePtr2.txt
#### ǰ����� ####
35 21 15 13 17 23 27 25 38 36
#### ������� ####
13 15 17 21 23 25 27 35 36 38
#### ������� ####
13 17 15 25 27 23 21 36 38 35

�����ĸ��ļ�: OnePtr3.txt
#### ǰ����� ####
81 53 46 49 67 55 58 73 77 87 83 90
#### ������� ####
46 49 53 55 58 67 73 77 81 83 87 90
#### ������� ####
49 46 58 55 77 73 67 53 83 90 87 81
*/
