/*	File: cas4-34T2B.c
	【例4-34】三次树转换为二叉树
	相关文件：cas4-34MakeTree.c	*/

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
TRINODE *RootT=NULL;		/* 三次树的根指针	*/
BINODE  *RootB=NULL;		/* 二叉树的根指针	*/
void error(char *);
void input(void);
void MakeTree(void);

/* 递归方法的前序遍历函数		*/
void preOrder(BINODE *node)
{
	if(!node)
		return;
	printf("%c ", node->key); 
	preOrder(node->left);
	preOrder(node->right);
}
/* 递归方法的中序遍历函数		*/
void symOrder(BINODE *node)
{
	if(!node)
		return;
	symOrder(node->left);
	printf("%c ", node->key); 
	symOrder(node->right);
}
/* 递归方法的后序遍历函数		*/
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
	if(t == NULL)		/* 空结点，返回 */
		return(NULL);
	b = (BINODE *)(malloc(sizeof(BINODE)));
	if(b == NULL)
		error("no space for RootT!"); 
	b->key = t->key; 			/* 复制结点值		*/
	b->left = b->right = NULL;	/* 左右子置空		*/
	if(t->sub[0])				/* 转换第一子树		*/
	{
		b->left = T2B(t->sub[0]);
		if(t->sub[1])			/* 转换第二子树		*/
		{
			b->left->right = T2B(t->sub[1]);
			if(t->sub[2])		/* 转换第三子树		*/
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
	printf("前序遍历:\n");
	preOrder(RootB);
	printf("\n");
	printf("中序遍历:\n");
	symOrder(RootB);
	printf("\n");
	printf("后序遍历:\n");
	postOrder(RootB);
	printf("\n");
	system("pause");
}
/*
输入哪个文件: TriTree1.txt
输入的五次树:
A(B(D,C),H,E(G,F))
前序遍历:
A B D C H E G F
中序遍历:
D C B H G F E A
后序遍历:
C D F G E H B A

输入哪个文件: TriTree2.txt
输入的五次树:
A(B,C(E,F(L,M),G),D(H,J,K))
前序遍历:
A B C E F L M G D H J K
中序遍历:
B E L M F G C H J K D A
后序遍历:
M L G F E K J H D C B A
*/
