/*	File: cas4-20MakeTree.c
	����4-20���������ű�ʾ�������
	ʵ�����Ӵ洢������ĵݹ�ǰ������ͺ������
	����ļ���cas4-20CreateTree.c	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
#define STACK struct stack
#define N   5
#define M 	60
#define NUMBEER 0
#define SYMBOL  1
NODE
{
	int num;
	NODE *sub[N];
};
STACK
{
	NODE *node;
	STACK *next;
};
STACK *Stack=NULL;
char   String[M];   /* �����ַ���	*/
int  Ptr;			/* �ַ�����ָ��	*/
NODE *Root;
void error(char *string)
{
	printf("%s\n", string);
	exit(0);
}
void input(void)
{
	int i=-1, c;  
	while( (c=getchar()) != EOF )
	{
		if(!isspace(c))			/* �ǿ��ַ�?	*/
			String[++i] = c;	/* �����ַ���ȥ */
	}
	String[++i] = '\0';
	printf("����������: \n%s\n", String); 
}
void push(NODE *node)
{
	STACK *s;
	s = (STACK *)(malloc(sizeof(STACK)));
	if(s == NULL)
		error("no space for stack!");
	s->node = node;
	s->next = Stack;
	Stack = s;
}
NODE *pop(void)
{
	NODE *node;
	STACK *s;
	if(Stack == NULL)
		return(NULL);
	node = Stack->node;
	s = Stack;
	Stack = s->next;
	free(s);
	return(node);
}
int GetData(int *key)
{
	char c;
	*key = 0;
	if(!isdigit(c = String[Ptr]))
	    return(0);     	/* ʧ�� */
	while(isdigit(c))	/* ��String��ȡһ�����ֵ */
	{
		*key = *key * 10 + String[Ptr] - '0';
		c = String[++Ptr];
	}
	if(c == ',' || c == '(' || c == ')')
	    return(1); 		/* �ɹ� */
	return(0);         	/* ʧ�� */
}
int GetSymbol(char symbol) 
{
	if(String[Ptr++] == symbol)	/* ��String��ȡһ������ */
		return(1); 		/* �ɹ� */
	Ptr--;
	return(0);         	/* ʧ�� */
}
void MakeNode(void)
{
	int num, j;
	int k=0;
	NODE *node;
	if(!GetSymbol('('))			/* 1. ȡ������	*/
	    return;			  /* ȡ����(����)������	*/
	while(GetData(&num))		/* 2. ȡ�ӽ��	*/
	{  
		node = (NODE *)(malloc(sizeof(NODE)));
		if(node == NULL)
			error("no space!"); 
		for(j=0; j<N; j++)
			node->sub[j] = NULL;
		node->num = num;
		Stack->node->sub[k] = node;
		push(node);
		MakeNode();
		if(GetSymbol(','))		/* 3. ȡ����	*/
		{
			k++;
			pop();
		}
		else if(GetSymbol(')'))	/* 4. ȡ������	*/
			pop();
		else
			error("format error!"); 
	}
}
void MakeTree()
{
	int num, j;
	if(GetData(&num))	 /* ��ȡ�����ֵ	*/
	{	
		Root = (NODE *)(malloc(sizeof(NODE)));
		if(Root == NULL)
			error("no space for Root!"); 
		for(j=0; j<N; j++)
			Root->sub[j] = NULL;
		Root->num = num;
		push(Root);
		MakeNode();
	}
	else
		error("Empty tree!"); 
} 
/*
3D, 4H, 4I, 3E, 4J, 3F, 2B, 4K, 4L, 3G, 2C, 1A
*/