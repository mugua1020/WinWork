/*	File: cas4-20MakeTree.c
	【例4-20】输入括号表示的五次树
	实现链接存储五次树的递归前序遍历和后序遍历
	相关文件：cas4-20CreateTree.c	*/

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
char   String[M];   /* 输入字符串	*/
int  Ptr;			/* 字符数组指针	*/
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
		if(!isspace(c))			/* 是空字符?	*/
			String[++i] = c;	/* 将空字符滤去 */
	}
	String[++i] = '\0';
	printf("输入的五次树: \n%s\n", String); 
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
	    return(0);     	/* 失败 */
	while(isdigit(c))	/* 从String中取一个结点值 */
	{
		*key = *key * 10 + String[Ptr] - '0';
		c = String[++Ptr];
	}
	if(c == ',' || c == '(' || c == ')')
	    return(1); 		/* 成功 */
	return(0);         	/* 失败 */
}
int GetSymbol(char symbol) 
{
	if(String[Ptr++] == symbol)	/* 从String中取一个符号 */
		return(1); 		/* 成功 */
	Ptr--;
	return(0);         	/* 失败 */
}
void MakeNode(void)
{
	int num, j;
	int k=0;
	NODE *node;
	if(!GetSymbol('('))			/* 1. 取左括号	*/
	    return;			  /* 取不到(空树)，返回	*/
	while(GetData(&num))		/* 2. 取子结点	*/
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
		if(GetSymbol(','))		/* 3. 取逗号	*/
		{
			k++;
			pop();
		}
		else if(GetSymbol(')'))	/* 4. 取右括号	*/
			pop();
		else
			error("format error!"); 
	}
}
void MakeTree()
{
	int num, j;
	if(GetData(&num))	 /* 获取根结点值	*/
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