/* File: cas4-31MakeBiTree.c
	【例4-31】输入括号表示的二叉树，链接存储二叉树
	相关文件：cas4-31CreateBiTree.c	*/

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
char String[60];	/* 输入字符串	*/
int  Ptr=0;			/* 字符数组指针 */

void error(char *string)
{
	printf("%s\n", string);
	system("pause");
	exit(0);
}
void input(void)		/* 输入树的括号表示	*/
{
	int i=0, c;  
	printf("请输入括号表示的二叉树"); 
	printf("(以控制符^Z+换行符为结束):\n"); 
	while( (c=getchar()) != EOF )
		if(!isspace(c))			/* empty char?		*/
			String[i++] = c;	/* remove empty char */
	String[i] = '\0';
	printf("输入的二叉树: \n%s\n", String); 
}
int GetData(int *key)
{
	*key = 0;
	if(!isdigit(String[Ptr]))
		return(0);	/* 取值失败	*/
	/* get a data from string */
	while(isdigit(String[Ptr]))
		*key = *key * 10 + String[Ptr++] - '0';
    return(1); 	/* 取值成功	*/
}
int GetSymbol(char symbol) 
{
	/* get a symbol from string */
	if(String[Ptr] != symbol)
		return(0);  /* 取符号失败	*/
	Ptr++;
	return(1); 		/* 取符号成功	*/
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

void MakeBitree()		/* 生成和存储树	*/
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