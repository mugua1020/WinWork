/* File: exe4-25-1LineStackPreOrder.c
	��ϰ��4-25-1���������������ű�ʾ�������
	����˳��ջ���Էǵݹ鷽��ʵ������ǰ�����	*/

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

/* ˳��ջ�����ݶ���	*/
NODE *stack[100];
int Top=-1;

/* ˳��ջ�Ľ�ջ����	*/
void push(NODE *node)
{
	stack[++Top] = node;
}

/* ˳��ջ�ĳ�ջ����	*/
NODE *pop()
{
	NODE *node;
	node = stack[Top--];
	return(node);
}

/* �Էǵݹ鷽����ǰ���������		*/
void preOrder(NODE *root)
{
	NODE *node;
	int   i ;
	/* �������´���		*/


}
