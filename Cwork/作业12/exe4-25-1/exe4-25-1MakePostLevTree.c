/* File: exe4-25-1MakePostLevTree.c
	��ϰ��4-25-1���������������ű�ʾ�������
	�������ĺ������(postorder)��α�ʾ(level)
	�������Ӵ洢����							*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
#define STACKNODE struct stacknode
#define N   5
#define M 	1000
#define SYMBOL  1
/* ���������ݺͱ�������	*/
NODE
{
	char key;
	NODE *sub[N];
};
extern NODE *Root;

/* ���������ַ����ı�������	*/
char  String[M];	/* �����ַ���	*/
short Ptr=-1;		/* �ַ�����ָ�� */

/* ��������ջ���ݺͱ�������	*/
STACKNODE
{
	NODE *node;
	short level;
	STACKNODE *next;
};
STACKNODE *StackTop=NULL;
short top_level=0;	/* ջ������ţ�0��ʾ��ջ	*/
	
void error(char *string)	/* ��������		*/
{
	printf("%s\n", string);
	exit(0);
}

void input(void)		/* �������ĺ���������ű�ʾ	*/
{
	int i=-1, c;  
	while( (c=getchar()) != EOF )
		if(!isspace(c))			/* empty char?		*/
			String[++i] = c;	/* remove empty char */
	String[++i] = '\0';
	printf("����������: \n%s\n", String); 
}

short GetNode(short *level, char *key)
{
	char c;
	*level = 0;
	/* get level from string */
	if(!isdigit(c = String[++Ptr]))
	    return(0);     	/* parse fail */
	while(isdigit(c))
	{
		*level = *level * 10 + String[Ptr] - '0';
		c = String[++Ptr];
	}
	if(!isalpha(c))
		return(0);      /* parse fail */
	*key = c;
	if((c = String[++Ptr]) == ',' ||
		c == '\0' )
	    return(1); 		/* parse success */
	else
		return(0);      /* parse fail */
}

void pushNode(NODE *node, short level)
{
	STACKNODE *stackNode;
	stackNode = (STACKNODE *)(malloc(sizeof(STACKNODE)));
	if(stackNode == NULL)
		error("no space for stackNode!");
	stackNode->node = node;
	stackNode->level = level;
	stackNode->next = StackTop;
	StackTop = stackNode;
}
NODE *popNode(void)
{
	NODE *node;
	STACKNODE *stackNode;
	if(StackTop == NULL)
		return(NULL);
	node = StackTop->node;
	stackNode = StackTop;
	StackTop = stackNode->next;
	free(stackNode);
	return(node);
}
void LinkNode(NODE *node, NODE *stackNode)
{
	short j=0;
	while(node->sub[j] != NULL)
		j++;
	node->sub[j] = stackNode;
}
void MakeTree()	/* ���ɺʹ洢��		*/
{
	short level, j;
	short k=0;
	char key;
	NODE *node, *stackNode;
	while(GetNode(&level, &key) == 1)
	{
//		printf("%d,%c + ", level, key);
		node = (NODE *)(malloc(sizeof(NODE)));
		if(node == NULL)
			error("no space!"); 
		for(j=0; j<N; j++)
			node->sub[j] = NULL;
		node->key = key;
		while(StackTop != NULL &&
			  level == StackTop->level - 1)
		{
			stackNode = popNode();
			LinkNode(node, stackNode);
		}
		if(level > 1)
		{
			pushNode(node, level);
			top_level = level;
		}
		else
		{
			while(stackNode = popNode())
				LinkNode(node, stackNode);
			Root = node;
			return;
		}
	}
	printf("\n");
} 