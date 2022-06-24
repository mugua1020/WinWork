/* File: cas4-33MakeTree.c
	����4-33������ǰ����������ɶ�����	*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define	M  30
#define NODE struct node
NODE
{
	char key;
	NODE *left, *right;
};
NODE *Root=NULL;
//char *Pre =	"BHDAEKCGI";
//char *Sym =	"ADEKHGCIB";
char Pre[M], Sym[M];

void error(char *string)
{
	printf("%s\n", string);
	system("pause");
	exit(0);
}
int rootInSym(int s1, int s2, char key)
{	/* �������ַ�������Ѱ�����ĸ���key��	*/
	int i;
	for(i=s1; i<=s2; i++)
		if( Sym[i] == key )		
			return(i);	
	error("no root in Sym");
	return(-1);
}
NODE *MakeTree(int p1, int p2, int s1, int s2)
{
	NODE *node;
	int r;
//	int delta;
	if(p1 > p2 || s1 > s2)
		return(NULL);
	if ((node =(NODE*)malloc(sizeof(NODE))) == NULL) 
		error("no sppace");
	node->key = Pre[p1];
	if (p1 == p2)
		node->left = node->right = NULL;
	else	
	{
		r = rootInSym(s1, s2, node->key);
		node->left  = MakeTree(p1+1, r-s2+p2, s1, r-1);
		node->right = MakeTree(r-s2+p2+1, p2, r+1, s2);
	}
	return(node);
}
/* �ݹ鷽����ǰ���������		*/
void preOrder(NODE *node)
{
	if(!node)
		return;
	printf("%c ", node->key); 
	preOrder(node->left);
	preOrder(node->right);
}
/* �ݹ鷽���������������		*/
void symOrder(NODE *node)
{
	if(!node)
		return;
	symOrder(node->left);
	printf("%c ", node->key); 
	symOrder(node->right);
}
/* �ݹ鷽���ĺ����������		*/
void postOrder(NODE *node)
{
	if(!node)
		return;
	postOrder(node->left);
	postOrder(node->right);
	printf("%c ", node->key); 
}
void main()
{
	/* 1. �����ַ��� */
	printf("������ǰ�����: "); 
	scanf("%s", Pre); 
	printf("�������������: "); 
	scanf("%s", Sym); 
	/* 2. ������ */
	Root = MakeTree(0, strlen(Pre)-1, 0, strlen(Sym)-1);
	/* 3. ���ı��� */
	printf("ǰ�����: \n"); 
	preOrder(Root);
	printf("\n");
	printf("�������: \n"); 
	symOrder(Root);
	printf("\n");
	printf("�������: \n"); 
	postOrder(Root);
	printf("\n");
	system("pause");
}
/*
����ʾ��
BHDAEKCGI
ADEKHGCIB
������ǰ�����: BHDAEKCGI
�������������: ADEKHGCIB
ǰ�����:
B H D A E K C G I
�������:
A D E K H G C I B
�������:
A K E D G I C H B

ABCDEFGH
BDCAGFHE
������ǰ�����: ABCDEFGH
�������������: BDCAGFHE
ǰ�����:
A B C D E F G H
�������:
B D C A G F H E
�������:
D C B G H F E A
*/
