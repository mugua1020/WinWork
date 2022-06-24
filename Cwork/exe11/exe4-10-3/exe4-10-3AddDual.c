/*	File: exe4-10-3AddDual.c
	【习题4-10-3】顺序存储的线性表基本操作程序
	相关文件：exe4-10-3linkListMain.c
			  exe4-10-3linkListSub.c	*/

#include <stdio.h>
#include <stdlib.h>
#define NODE struct node
NODE
{
	int num;
	NODE *next;
};
extern int  n;
void error(char *);

void AddDual(NODE *head)
{
	int key, suc1, suc2;
	NODE   *node, *tmp;  
	printf("**** 请输入结点key和双结点suc1,suc2 ****\n");
	scanf("%d%d%d", &key, &suc1, &suc2);
	for(node=head->next; node && node->num!=key; node=node->next)
		;
	if(node == NULL)
		error("查无结点key");
	/* 根据用户输入的结点值key，添加双结点suc1和suc2	*/
	else
	{	//可以把这部分抽象为函数
		tmp =(NODE*)malloc(sizeof(NODE));
		if(!tmp)
		error("no memory space");
		else
		{
			tmp->next = node->next;
			tmp->num = suc1;
			node->next = tmp;
			node = node->next;
		}

		tmp =(NODE*)malloc(sizeof(NODE));
		if(!tmp)
		error("no memory space");
		else
		{
			tmp->next = node->next;
			tmp->num = suc2;
			node->next = tmp;
			node = node->next;
		}
	}
	
	printf("**** 添加双结点已完成 ****\n");
}
