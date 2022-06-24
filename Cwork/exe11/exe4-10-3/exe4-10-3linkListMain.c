/*	File: exe4-10-3linkListMain.c
	【习题4-10-3】顺序存储的线性表基本操作程序
	相关文件：exe4-10-3AddDual.c
			  exe4-10-3linkListSub.c	*/

//gcc .\exe4-10-3linkListMain.c .\exe4-10-3linkListSub.c .\exe4-10-3AddDual.c -fexec-charset=gbk -o exe4-10-3.exe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define	MinMenu   0
/* 请修改MaxMenu	*/
#define	MaxMenu   7
#define NODE struct node
NODE
{
	int num;
	NODE *next;
};
int  n;
void insert(NODE *);
void InputList(NODE *);
void SearchNode(NODE *);
void AddNode(NODE *);
void RemoveNode(NODE *);
void InsertOrder(NODE *);
void PrintList(NODE *);
void ExitTask(NODE *);
void AddDual(NODE *);
/* 请增加添加双结点函数	*/


void error(char *error_msg)
{
	printf("**** %s ****\n", error_msg);
	exit(0);
}

void main()
{
	char txt_item[30];
	NODE *Head;
	/* 修改MenuTitle和MenuFp[]	*/
	char *MenuTitle[]={
		"输入线性表(0)", "查找结点(1)", "添加结点(2)",
		"删除结点(3)", "插入排序(4)","输出线性表(5)", 
		"添加双结点(6)", "退出(7)"};
	void (* MenuFp[])(NODE *)={
		InputList, SearchNode, AddNode, 
		RemoveNode, InsertOrder, PrintList,  
		AddDual, ExitTask};

	int MenuItem=MinMenu, i;

	/* 创建有哨兵的空链表 */
	Head = (NODE *)(malloc(sizeof(NODE)));
	if(Head == NULL)
	   error("no memory space");  
	Head->next = NULL;
	while(MenuItem != MaxMenu)
	{
		/* 显示菜单		*/
		printf("\n**** 链接存储的线性表基本操作程序 ****\n");
		for(i=MinMenu; i<=MaxMenu; i++)
			printf("%s%c", MenuTitle[i], 
				((i+1)%3==0 || i==MaxMenu) ? '\n' : '\t');
		printf("请选择命令[%d-%d]：", MinMenu, MaxMenu);
		/* 输入命令选择		*/
		scanf("%s", txt_item);
		if(! isdigit(txt_item[0]) )
			printf("**** 无效命令 ****\n");
		else
		{
			sscanf(txt_item, "%d", &MenuItem);
			if(MenuItem < MinMenu || MenuItem > MaxMenu)
				printf("**** 无效命令 ****\n");
			else	/* 调用对应的函数	*/
				(*MenuFp[MenuItem])(Head);
		}
	}
}
/*
10
7 3 4 2 8 12 5 11 6 22
9
7 3 4 
8 12 5 11 6 22
12
7 3 6 22 4 2 8 12 5 11 18 43
*/
