/*	File: exe4-10-3linkListSub.c
	【习题4-10-3】顺序存储的线性表基本操作程序
	相关文件：exe4-10-3linkListMain.c
			  exe4-10-3AddDual.c	*/

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

void PrintList(NODE *head)
{
	NODE *node;
	int j;
	printf("%d nodes in list.\n", n);
	for(j=0, node=head->next; node; node=node->next, j++)
		printf("node[%d] = %d%c", j, node->num, (j+1)%5==0 ? '\n' : '\t');
	if(j%5)
		printf("\n");
}
void InputList(NODE *head)
{
	int i, num; 
	NODE   *node, *tail;  
	printf("**** 请输入结点数和各个整型结点值 ****\n");
	scanf("%d", &n);
	if(n < 1)
	    error("invalid n");
	head->next = NULL;
	tail = head;
	for(i=0; i<n; i++)
	{
		node=(NODE *)(malloc(sizeof(NODE)));
		if(node == NULL)
			error("no space"); 
		scanf("%d", &num);
		node->num = num;
		tail->next = node;
		tail = tail->next;
	}
	tail->next = NULL;
	printf("**** 线性表已输入 ****\n");
}
void SearchNode(NODE *head)
{
	int j, key;
	NODE   *node;  
	printf("**** 请输入结点key ****\n");
	scanf("%d", &key);
	/* 根据用户输入的结点值key，查找结点	*/
	for(j=0, node=head->next; node && key!=node->num; node=node->next, j++)
		;
	if(node == NULL)
		error("查无结点key");
	printf("node[%d] = %d\n", j, node->num);
	printf("**** 查找结点已完成 ****\n");
}
void AddNode(NODE *head)
{
	int key, suc;
	NODE   *node, *tmp;
	printf("**** 请输入结点值key和待添加的结点值suc ****\n");
	scanf("%d%d", &key, &suc);
	/* 根据用户输入的结点值key和待添加的结点值suc，	*/
	/* 在结点key后面添加结点suc						*/
	for(node=head->next; node && node->num!=key; node=node->next)
		;
	if(node == NULL)
		error("查无结点key");
	tmp =(NODE *)(malloc(sizeof(NODE)));
	if(tmp == NULL)
		error("no space"); 
	tmp->num = suc;
	tmp->next = node->next;
	node->next = tmp;
	n++;
	printf("**** 添加结点已完成 ****\n");
}
void RemoveNode(NODE *head)
{
	int key;
	NODE   *node, *prev;
	printf("**** 请输入待删除的结点值key ****\n");
	scanf("%d", &key);
	/* 根据用户输入的结点值key，删除结点key	*/
	for(prev=head; prev->next && prev->next->num!=key; prev=prev->next)
		;
	if(prev->next == NULL)
		error("查无结点key");
	node = prev->next;
	prev->next = node->next;
	free(node);
	n--;
	printf("**** 删除结点已完成 ****\n");
}
void InsertOrder(NODE *head)
{
    NODE *unsort, *key, *node;
    if(head->next==NULL || head->next->next==NULL)
        return;						/* 空链表或者链表中只有一个结点	*/
    unsort = head->next->next; 		/* 初始: S={k0}, U=K-{k0}		*/
    head->next->next = NULL;
    while(unsort) 					/* U非空，进行循环				*/
    {
		key = unsort; 				/* U=U-{key}					*/
		unsort = key->next;
		for(node=head; node->next; node=node->next)
			if(key->num <= node->next->num) /* 定位插入点			*/
				break; 
		key->next = node->next; 	/* 将key插入S，保持S有序		*/
		node->next = key; 		
    }
	printf("**** 插入排序已完成 ****\n");
}
void ExitTask(NODE *head)
{
	printf("**** 再见! 祝你好运! ****\n");
	system("pause");
}
