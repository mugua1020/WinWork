/* File: cas4-31LinkBiTree.c
	【例4-31】输入括号表示的二叉树，链接存储二叉树
	递归实现前序遍历，中序遍历和后序遍历
	相关文件：cas4-31MakeBiTree.c	*/

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

/* MakeLnkTree.c 中定义的函数	*/
void input(void);
void MakeBitree(void);

/* 递归方法的前序遍历函数		*/
void preOrder(NODE *node)
{
	if(!node)
		return;
	printf("%d ", node->key); 
	preOrder(node->left);
	preOrder(node->right);
}
/* 递归方法的中序遍历函数		*/
void symOrder(NODE *node)
{
	if(!node)
		return;
	symOrder(node->left);
	printf("%d ", node->key); 
	symOrder(node->right);
}
/* 递归方法的后序遍历函数		*/
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
	/* 1. 输入字符串 */
	input();
	/* 2. 生成树 */
	MakeBitree();
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
运行示例1
请输入括号表示的二叉树(以控制符^Z+换行符为结束):
5( 1 (,3 (2 , 4) ), 8 (6 (,7 ),))
输入的二叉树:
5(1(,3(2,4)),8(6(,7),))
前序遍历:
5 1 3 2 4 8 6 7
中序遍历:
1 2 3 4 5 6 7 8
后序遍历:
2 4 3 1 7 6 8 5

运行示例2
请输入括号表示的二叉树(以控制符^Z+换行符为结束):
  5(32	(,
	72(40,7)  ),
12(		4,8( 3,)  )  )
输入的二叉树:
5(32(,72(40,7)),12(4,8(3,)))
前序遍历:
5 32 72 40 7 12 4 8 3
中序遍历:
32 40 72 7 5 4 12 3 8
后序遍历:
40 7 72 32 4 3 8 12 5

运行示例3
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
输入的二叉树:
30(5(32(2,72(40,7(,12(4,8)))),43),6(3,17(,13)))
前序遍历:
30 5 32 2 72 40 7 12 4 8 43 6 3 17 13
中序遍历:
2 32 40 72 7 4 12 8 5 43 30 3 6 17 13
后序遍历:
2 40 4 8 12 7 72 32 43 5 3 13 17 6 30
*/
