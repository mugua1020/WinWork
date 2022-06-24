/* File: exe4-25-1LineStackPre.c
	【习题4-25-1】输入后序遍历括号表示的五次树
	采用顺序栈，以非递归方法实现树的前序遍历
	相关文件：exe4-25-1MakePostLevTree.c
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

/* MakePostLevTree.c 中定义的函数					*/
void input(void);		/* 输入树的后序遍历括号表示	*/
void MakeTree(void);	/* 生成和存储树				*/
/* LineStackPreOrder.c 中定义的函数					*/
void preOrder(NODE *);

void main()
{
	/* 1. 输入字符串 */
	printf("请输入后序遍历括号表示的五次树"); 
	printf("(以控制符^Z+换行符为结束):\n"); 
	input();
	/* 2. 生成树 */
	MakeTree();
	/* 3. 非递归方法实现树的前序遍历 */
	printf("前序遍历: \n"); 
	preOrder(Root);
	printf("\n");
	system("pause");
}
/*
请输入后序遍历括号表示的五次树(以控制符^Z+换行符为结束):
2b,3d, 3e,3 f
  , 3 g , 2c ,2h, 2j ,3
m,4
p,4q,4r
,3n,2k,1a
^Z
输入的五次树:
2b,3d,3e,3f,3g,2c,2h,2j,3m,4p,4q,4r,3n,2k,1a
前序遍历:
a b c d e f g h j k m n p q r

请输入后序遍历括号表示的五次树(以控制符^Z+换行符为结束):
3D , 4 H, 4I
, 3E,   4J,
3F, 2B , 4K, 4L, 3G, 2C, 1A
^Z
输入的五次树:
3D,4H,4I,3E,4J,3F,2B,4K,4L,3G,2C,1A
前序遍历:
A B D E H I F J C G K L
*/