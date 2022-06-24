/*	File: exe4-9-2lineListSub.c
	【习题4-9-2】顺序存储的线性表基本操作程序
	相关文件：exe4-9-2lineListMain.c
			  exe4-9-2lineLook.c	*/

#include <stdio.h>
#include <stdlib.h>
#define	M   1000
void error(char *);

void PrintList(int *a, int *n)
{
	int j;
	printf("%d nodes in list.\n", *n);
	for(j=0; j<*n; j++)
		printf("a[%d] = %d%c", j, a[j], (j+1)%5==0 ? '\n' : '\t');
	if(j%5)
		printf("\n");
}
void InputList(int *a, int *n)
{
	int  j;
	printf("**** 请输入结点数和各个整型结点值 ****\n");
	scanf("%d", n);
	if(*n > M-1 || *n < 1)
	    error("invalid n");
	for(j=0; j<*n; j++)
	    scanf("%d", &a[j]);
	printf("**** 线性表已输入 ****\n");
}
void SearchNode(int *a, int *n)
{
	int j;
	printf("**** 请输入结点地址 ****\n");
	scanf("%d", &j);
	/* 根据用户输入的结点地址j查找结点	*/
	if(j<0 || j>(*n)-1)
		error("结点地址超界");
	printf("node(%d) = %d\n", j, a[j]);
	printf("**** 查找结点已完成 ****\n");
}
void AddNode(int *a, int *n)
{
	int i, k, key, suc;
	printf("**** 请输入结点值key和待添加的结点值suc ****\n");
	scanf("%d%d", &key, &suc);
	/* 根据用户输入的结点值key和待添加的结点值suc	*/
	/* 在结点key后面添加结点suc						*/
	for(i=0; i<(*n) && key!=a[i]; i++)
		;
	if(i<0 || i>(*n)-1)
		error("查无结点key");
	for(k=(*n)-1; k>i; k--)
		a[k+1] = a[k];
	a[i+1] = suc;
	(*n)++;
	printf("**** 添加结点已完成 ****\n");
}
void RemoveNode(int *a, int *n)
{
	int i, k, key;
	printf("**** 请输入待删除的结点值key ****\n");
	scanf("%d", &key);
	/* 根据用户输入的结点值key，删除结点key	*/
	for(i=0; i<(*n) && key!=a[i]; i++)
		;
	if(i<0 || i>(*n)-1)
		error("查无结点key");
	for(k=i; k<(*n); k++)
		a[k] = a[k+1];
	(*n)--;
	printf("**** 删除结点已完成 ****\n");
}
void InsertOrder(int *a, int *n)
{
	int key, j, k;
	for(j=1; j <(*n); j++)
	{ 
		key=a[j];							/* (1) 暂存	*/
		for(k=j-1; key<a[k] && k>=0; k--)	/* (2) 定位	*/
			a[k+1] = a[k];					/* (3) 移动	*/
		a[++k] =key;						/* (4) 插入	*/
	}
	printf("**** 插入排序已完成 ****\n");
}
void ExitTask(int *a, int *n)
{
	printf("**** 再见! 祝你好运! ****\n");
	system("pause");
}
