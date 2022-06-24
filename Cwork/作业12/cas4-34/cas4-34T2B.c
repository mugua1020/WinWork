/*	File: cas4-34T2B.c
	����4-34��������ת��Ϊ������
	����ļ���cas4-34MakeTree.c	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  TRINODE  struct  trinode
#define  BINODE   struct  binode
TRINODE 
{
	char  key;
	TRINODE  *sub[3];
}; 
BINODE
{
	char key;
	BINODE *left, *right;
};
TRINODE *RootT=NULL;		/* �������ĸ�ָ��	*/
BINODE  *RootB=NULL;		/* �������ĸ�ָ��	*/
void error(char *);
void input(void);
void MakeTree(void);

/* �ݹ鷽����ǰ���������		*/
void preOrder(BINODE *node)
{
	if(!node)
		return;
	printf("%c ", node->key); 
	preOrder(node->left);
	preOrder(node->right);
}
/* �ݹ鷽���������������		*/
void symOrder(BINODE *node)
{
	if(!node)
		return;
	symOrder(node->left);
	printf("%c ", node->key); 
	symOrder(node->right);
}
/* �ݹ鷽���ĺ����������		*/
void postOrder(BINODE *node)
{
	if(!node)
		return;
	postOrder(node->left);
	postOrder(node->right);
	printf("%c ", node->key); 
}
BINODE *T2B(TRINODE *t)
{
	BINODE  *b;
	if(t == NULL)		/* �ս�㣬���� */
		return(NULL);
	b = (BINODE *)(malloc(sizeof(BINODE)));
	if(b == NULL)
		error("no space for RootT!"); 
	b->key = t->key; 			/* ���ƽ��ֵ		*/
	b->left = b->right = NULL;	/* �������ÿ�		*/
	if(t->sub[0])				/* ת����һ����		*/
	{
		b->left = T2B(t->sub[0]);
		if(t->sub[1])			/* ת���ڶ�����		*/
		{
			b->left->right = T2B(t->sub[1]);
			if(t->sub[2])		/* ת����������		*/
				b->left->right->right = T2B(t->sub[2]);
		}
	}
	return(b);
}
main()
{
	input();
	MakeTree();
	RootB = T2B(RootT);
	printf("ǰ�����:\n");
	preOrder(RootB);
	printf("\n");
	printf("�������:\n");
	symOrder(RootB);
	printf("\n");
	printf("�������:\n");
	postOrder(RootB);
	printf("\n");
	system("pause");
}
/*
�����ĸ��ļ�: TriTree1.txt
����������:
A(B(D,C),H,E(G,F))
ǰ�����:
A B D C H E G F
�������:
D C B H G F E A
�������:
C D F G E H B A

�����ĸ��ļ�: TriTree2.txt
����������:
A(B,C(E,F(L,M),G),D(H,J,K))
ǰ�����:
A B C E F L M G D H J K
�������:
B E L M F G C H J K D A
�������:
M L G F E K J H D C B A
*/
