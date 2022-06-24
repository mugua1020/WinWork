/* File: cas4-31MakeBiTree.c
	����4-31���������ű�ʾ�Ķ����������Ӵ洢������
	����ļ���cas4-31CreateBiTree.c	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
NODE
{
	int key;
	NODE *left, *right;
};
extern NODE *Root;
char String[60];	/* �����ַ���	*/
int  Ptr=0;			/* �ַ�����ָ�� */

void error(char *string)
{
	printf("%s\n", string);
	system("pause");
	exit(0);
}
void input(void)		/* �����������ű�ʾ	*/
{
	int i=0, c;  
	printf("���������ű�ʾ�Ķ�����"); 
	printf("(�Կ��Ʒ�^Z+���з�Ϊ����):\n"); 
	while( (c=getchar()) != EOF )
		if(!isspace(c))			/* empty char?		*/
			String[i++] = c;	/* remove empty char */
	String[i] = '\0';
	printf("����Ķ�����: \n%s\n", String); 
}
int GetData(int *key)
{
	*key = 0;
	if(!isdigit(String[Ptr]))
		return(0);	/* ȡֵʧ��	*/
	/* get a data from string */
	while(isdigit(String[Ptr]))
		*key = *key * 10 + String[Ptr++] - '0';
    return(1); 	/* ȡֵ�ɹ�	*/
}
int GetSymbol(char symbol) 
{
	/* get a symbol from string */
	if(String[Ptr] != symbol)
		return(0);  /* ȡ����ʧ��	*/
	Ptr++;
	return(1); 		/* ȡ���ųɹ�	*/
}
NODE *newNode(int key)
{
	NODE *node;
	node = (NODE *)(malloc(sizeof(NODE)));
	if(node == NULL)
		error("no space!"); 
	node->left = node->right = NULL;
	node->key = key;
	return(node);
}
void MakeNode(NODE *root)
{
	int key;
	if(!GetSymbol('('))	/* 1. get '('	*/
	    return;
	if(GetData(&key))	/* 2. get left	*/
	{  
		root->left = newNode(key);
		MakeNode(root->left);
	}
	if(!GetSymbol(','))	/* 3. get ','	*/
		error("missing , !"); 
	if(GetData(&key))	/* 4. get right	*/
	{  
		root->right = newNode(key);
		MakeNode(root->right);
	}
	if(!GetSymbol(')'))	/* 5. get ')'	*/
		error("missing ) !"); 
	if(root->right == NULL &&
		root->left == NULL)
		error("no node !"); 
}

void MakeBitree()		/* ���ɺʹ洢��	*/
{
	int key;
	if(GetData(&key))	/* get node		*/
	{	
		Root = newNode(key);
		MakeNode(Root);
	}
	else
		error("Empty tree!"); 
} 