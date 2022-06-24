/* File: cas4-20LinkTree.c
	����4-20���������ű�ʾ�������
	ʵ�����Ӵ洢�������ǰ�����,��������ͺ������
	����ļ���cas4-20MakeTree.c	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
#define	M		20		/* ��������			*/
#define	MAX	 	M-1 	/* ��βָ������ֵ */
#define	MIN	 	0   	/* ����ָ�����Сֵ	*/
#define	EMPTY	MIN-1	/* �ն�ָ��ֵ		*/
#define N   5
NODE
{
	int num;
	NODE *sub[N];
};
NODE *Q[M];			/* ѭ������ָ������		*/
int	Top=EMPTY; 		/* ����ָ�룬��ʼΪ�ն�	*/
int	Tail=EMPTY; 	/* ��βָ�룬��ʼΪ�ն�	*/

NODE *Root=NULL;

/* MakeLnkTree.c �ж���ĺ���	*/
void input(void);
void MakeTree(void);
void error(char *);

void enQueue(NODE *node)
{
	if((Tail+1) % M == Top)	
		error("�����(overflow)"); 	/* �����(overflow)	*/
	if(Top<EMPTY || Top>MAX || Tail<EMPTY || Tail>MAX)
		error("�Ƿ�����"); 			/* �Ƿ�				*/
	/* ���¶���ָ��			*/
	Tail = (Tail + 1) % M; 
	if(Top == EMPTY)
		Top = Tail;
	Q[Tail] = node;					/* �����������		*/
}
NODE *deQueue(void)
{
	NODE *node;
	if(Top<EMPTY || Top>MAX || Tail<EMPTY || Tail>MAX)
		error("�Ƿ�����");			/* �Ƿ�				*/
	if(Top == EMPTY)
		return(NULL);
	node = Q[Top];
	/* ���¶���ָ��			*/
	if(Top != Tail)					/* ��������			*/
		Top = (Top + 1) % M;
	else  							/* ���գ���Ϊ�ն�	*/
		Top = Tail = EMPTY;
	return(node); 
}
/* ǰ���������preOrder()		*/
void preOrder(NODE *node)
{
	int i;
	if(!node)
		return;
	printf("%d ", node->num); 
  	for(i=0; i<N; i++)
		preOrder(node->sub[i]);
}
/* �����������postOrder()	*/
void postOrder(NODE *node)
{
	int i;
	if(!node)
		return;
  	for(i=0; i<N; i++)
		postOrder(node->sub[i]);
	printf("%d ", node->num); 
}
/* ��α�������postOrder()	*/
void levelOrder(NODE *node)
{
	int i;
	if(!node)
		return;
	enQueue(node);
  	while(node = deQueue())
	{
		printf("%d ", node->num); 
		for(i=0; i<N; i++)
			if(node->sub[i])
				enQueue(node->sub[i]);
		
	}
}
void main()
{
	/* 1. �����ַ��� */
	printf("���������ű�ʾ�������"); 
	printf("(�Կ��Ʒ�^Z+���з�Ϊ����):\n"); 
	input();
	/* 2. ������ */
	MakeTree();
	/* 3. ����ǰ�������� */
	printf("ǰ�����: \n"); 
	preOrder(Root);
	printf("\n");
	printf("�������: \n"); 
	postOrder(Root);
	printf("\n");
	printf("��α���: \n"); 
	levelOrder(Root);
	printf("\n");
	system("pause");
}
/*  ����ʾ��1
���������ű�ʾ�������(�Կ��Ʒ�^Z+���з�Ϊ����):
5 (7, 12(4, 8,  19, 11) ,
		30 ,2 ,13(32
	,40(  3,17, 23) ) )

����������:
5(7,12(4,8,19,11),30,2,13(32,40(3,17,23)))
ǰ�����:
5 7 12 4 8 19 11 30 2 13 32 40 3 17 23
�������:
7 4 8 19 11 12 30 2 32 3 17 23 40 13 5
��α���:
5 7 12 30 2 13 4 8 19 11 32 40 3 17 23
*/

/*  ����ʾ��2
���������ű�ʾ�������(�Կ��Ʒ�^Z+���з�Ϊ����):
27  (14, 48 ,19 , 16( 52
	,30 (22, 20), 13),
	17 ( 23, 40, 73 ,35)  )

����������:
27(14,48,19,16(52,30(22,20),13),17(23,40,73,35))
ǰ�����:
27 14 48 19 16 52 30 22 20 13 17 23 40 73 35
�������:
14 48 19 52 22 20 30 13 16 23 40 73 35 17 27
��α���:
27 14 48 19 16 17 52 30 13 23 40 73 35 22 20
*/
