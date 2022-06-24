/* File: cas4-31LinkBiTree.c
	����4-31���������ű�ʾ�Ķ����������Ӵ洢������
	�ݹ�ʵ��ǰ���������������ͺ������
	����ļ���cas4-31MakeBiTree.c	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
NODE
{
	int key;
	NODE *left, *right;
};
NODE *Root=NULL;

/* MakeLnkTree.c �ж���ĺ���	*/
void input(void);
void MakeBitree(void);

/* �ݹ鷽����ǰ���������		*/
void preOrder(NODE *node)
{
	if(!node)
		return;
	printf("%d ", node->key); 
	preOrder(node->left);
	preOrder(node->right);
}
/* �ݹ鷽���������������		*/
void symOrder(NODE *node)
{
	if(!node)
		return;
	symOrder(node->left);
	printf("%d ", node->key); 
	symOrder(node->right);
}
/* �ݹ鷽���ĺ����������		*/
void postOrder(NODE *node)
{
	if(!node)
		return;
	postOrder(node->left);
	postOrder(node->right);
	printf("%d ", node->key); 
}
void main()
{
	/* 1. �����ַ��� */
	input();
	/* 2. ������ */
	MakeBitree();
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
����ʾ��1
���������ű�ʾ�Ķ�����(�Կ��Ʒ�^Z+���з�Ϊ����):
5( 1 (,3 (2 , 4) ), 8 (6 (,7 ),))
����Ķ�����:
5(1(,3(2,4)),8(6(,7),))
ǰ�����:
5 1 3 2 4 8 6 7
�������:
1 2 3 4 5 6 7 8
�������:
2 4 3 1 7 6 8 5

����ʾ��2
���������ű�ʾ�Ķ�����(�Կ��Ʒ�^Z+���з�Ϊ����):
  5(32	(,
	72(40,7)  ),
12(		4,8( 3,)  )  )
����Ķ�����:
5(32(,72(40,7)),12(4,8(3,)))
ǰ�����:
5 32 72 40 7 12 4 8 3
�������:
32 40 72 7 5 4 12 3 8
�������:
40 7 72 32 4 3 8 12 5

����ʾ��3
30(5(
	32	(2,
			72(40,
				7(,
					12(4, 8	)
				 )
			  )
		),43
	),6(3,17(,13))
  )
����Ķ�����:
30(5(32(2,72(40,7(,12(4,8)))),43),6(3,17(,13)))
ǰ�����:
30 5 32 2 72 40 7 12 4 8 43 6 3 17 13
�������:
2 32 40 72 7 4 12 8 5 43 30 3 6 17 13
�������:
2 40 4 8 12 7 72 32 43 5 3 13 17 6 30
*/
