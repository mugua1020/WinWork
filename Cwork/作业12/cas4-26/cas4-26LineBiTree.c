/*	File: cas4-26LineBiTree.c
	����4-26��˳��洢������	*/

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
int n=0;		/* �����n<=M		*/
void preOrder(BITREE *tree, int root)	/* ǰ���������	*/
{
	if(root < 0)
		return;
	printf("%s ", tree[root].key);
	preOrder(tree, tree[root].left);
	preOrder(tree, tree[root].right);
}
void symOrder(BITREE *tree, int root)	/* �����������	*/
{
	if(root < 0)
		return;
	symOrder(tree, tree[root].left);
	printf("%s ", tree[root].key);
	symOrder(tree, tree[root].right);
}
void postOrder(BITREE *tree, int root)	/* �����������	*/
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
	printf("�����ĸ��ļ�: ");
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
	printf("#### ǰ����� ####\n");
	preOrder(Tree, 0);
	printf("\n");
	printf("#### ������� ####\n");
	symOrder(Tree, 0);
	printf("\n");
	printf("#### ������� ####\n");
	postOrder(Tree, 0);
	printf("\n");
	system("pause");
}
/*
�����ĸ��ļ�: BiTree1.txt
#### ǰ����� ####
A B D G H C E F
#### ������� ####
B G D H A E F C
#### ������� ####
G H D B F E C A

�����ĸ��ļ�: BiTree2.txt
#### ǰ����� ####
35 21 15 13 17 23 27 25 38 36
#### ������� ####
13 15 17 21 23 25 27 35 36 38
#### ������� ####
13 17 15 25 27 23 21 36 38 35

�����ĸ��ļ�: BiTree3.txt
#### ǰ����� ####
81 53 46 49 67 55 58 73 77 87 83 90
#### ������� ####
46 49 53 55 58 67 73 77 81 83 87 90
#### ������� ####
49 46 58 55 77 73 67 53 83 90 87 81
*/
