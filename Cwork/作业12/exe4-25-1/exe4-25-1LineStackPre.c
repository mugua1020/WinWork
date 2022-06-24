/* File: exe4-25-1LineStackPre.c
	��ϰ��4-25-1���������������ű�ʾ�������
	����˳��ջ���Էǵݹ鷽��ʵ������ǰ�����
	����ļ���exe4-25-1MakePostLevTree.c
			  exe4-25-1LineStackPreOrder.c	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
#define N   5
NODE
{
	char key;
	NODE *sub[N];
};

NODE *Root=NULL;

/* MakePostLevTree.c �ж���ĺ���					*/
void input(void);		/* �������ĺ���������ű�ʾ	*/
void MakeTree(void);	/* ���ɺʹ洢��				*/
/* LineStackPreOrder.c �ж���ĺ���					*/
void preOrder(NODE *);

void main()
{
	/* 1. �����ַ��� */
	printf("���������������ű�ʾ�������"); 
	printf("(�Կ��Ʒ�^Z+���з�Ϊ����):\n"); 
	input();
	/* 2. ������ */
	MakeTree();
	/* 3. �ǵݹ鷽��ʵ������ǰ����� */
	printf("ǰ�����: \n"); 
	preOrder(Root);
	printf("\n");
	system("pause");
}
/*
���������������ű�ʾ�������(�Կ��Ʒ�^Z+���з�Ϊ����):
2b,3d, 3e,3 f
  , 3 g , 2c ,2h, 2j ,3
m,4
p,4q,4r
,3n,2k,1a
^Z
����������:
2b,3d,3e,3f,3g,2c,2h,2j,3m,4p,4q,4r,3n,2k,1a
ǰ�����:
a b c d e f g h j k m n p q r

���������������ű�ʾ�������(�Կ��Ʒ�^Z+���з�Ϊ����):
3D , 4 H, 4I
, 3E,   4J,
3F, 2B , 4K, 4L, 3G, 2C, 1A
^Z
����������:
3D,4H,4I,3E,4J,3F,2B,4K,4L,3G,2C,1A
ǰ�����:
A B D E H I F J C G K L
*/