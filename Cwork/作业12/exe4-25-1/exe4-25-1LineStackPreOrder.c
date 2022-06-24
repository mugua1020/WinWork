/* File: exe4-25-1LineStackPreOrder.c
	【习题4-25-1】输入后序遍历括号表示的五次树
	采用顺序栈，以非递归方法实现树的前序遍历	*/

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

/* 顺序栈的数据定义	*/
NODE *stack[100];
int Top=-1;

/* 顺序栈的进栈函数	*/
void push(NODE *node)
{
	stack[++Top] = node;
}

/* 顺序栈的出栈函数	*/
NODE *pop()
{
	NODE *node;
	node = stack[Top--];
	return(node);
}

/* 以非递归方法的前序遍历函数		*/
void preOrder(NODE *root)
{
	NODE *node;
	int   i ;
	/* 补齐以下代码		*/


}
