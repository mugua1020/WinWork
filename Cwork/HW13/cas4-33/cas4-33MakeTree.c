/* File: cas4-33MakeTree.c
	【例4-33】根据前序和中序生成二叉树	*/

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
{	/* 在中序字符串中找寻子树的根（key）	*/
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
/* 递归方法的前序遍历函数		*/
void preOrder(NODE *node)
{
	if(!node)
		return;
	printf("%c ", node->key); 
	preOrder(node->left);
	preOrder(node->right);
}
/* 递归方法的中序遍历函数		*/
void symOrder(NODE *node)
{
	if(!node)
		return;
	symOrder(node->left);
	printf("%c ", node->key); 
	symOrder(node->right);
}
/* 递归方法的后序遍历函数		*/
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
	/* 1. 输入字符串 */
	printf("请输入前序遍历: "); 
	scanf("%s", Pre); 
	printf("请输入中序遍历: "); 
	scanf("%s", Sym); 
	/* 2. 生成树 */
	Root = MakeTree(0, strlen(Pre)-1, 0, strlen(Sym)-1);
	/* 3. 树的遍历 */
	printf("前序遍历: \n"); 
	preOrder(Root);
	printf("\n");
	printf("中序遍历: \n"); 
	symOrder(Root);
	printf("\n");
	printf("后序遍历: \n"); 
	postOrder(Root);
	printf("\n");
	system("pause");
}
/*
运行示例
BHDAEKCGI
ADEKHGCIB
请输入前序遍历: BHDAEKCGI
请输入中序遍历: ADEKHGCIB
前序遍历:
B H D A E K C G I
中序遍历:
A D E K H G C I B
后序遍历:
A K E D G I C H B

ABCDEFGH
BDCAGFHE
请输入前序遍历: ABCDEFGH
请输入中序遍历: BDCAGFHE
前序遍历:
A B C D E F G H
中序遍历:
B D C A G F H E
后序遍历:
D C B G H F E A
*/
