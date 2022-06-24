/*	File: exe4-9-2lineListMain.c
	【习题4-9-2】顺序存储的线性表基本操作程序
	相关文件：exe4-9-2lineListSub.c
			  exe4-9-2lineLook.c	*/



//gcc .\exe4-9-2lineListMain.c .\exe4-9-2lineListSub.c .\exe4-9-2lineLook.c -fexec-charset=gbk -o exe4-9-2.exe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define	M   1000
#define	MinMenu   0
/* 请修改MaxMenu	*/
#define	MaxMenu   7
void InputList(int *, int *);
void SearchNode(int *, int *);
void AddNode(int *, int *);
void RemoveNode(int *, int *);
void InsertOrder(int *, int *);
void PrintList(int *, int *);
void Look(int *, int *);
void ExitTask(int *, int *);

/* 请增加查找前后件函数	*/

void error(char *error_msg)
{
	printf("\a**** %s ****\n", error_msg);
	exit(0);
}

int main()
{
	char txt_item[30];
	int a[M], n;
	/* 修改MenuTitle和MenuFp[]	*/
	char *MenuTitle[]={
		"输入线性表(0)", "查找结点(1)", "添加结点(2)",
		"删除结点(3)", "插入排序(4)","输出线性表(5)", 
		"查找前后件(6)",
		"退出(7)"};
	void (* MenuFp[])(int *, int *)={
		InputList, SearchNode, AddNode, 
		RemoveNode, InsertOrder, PrintList, Look, 
		ExitTask};

	int MenuItem=MinMenu, i;
	while(MenuItem != MaxMenu)
	{
		/* 显示菜单		*/
		printf("\n**** 顺序存储的线性表基本操作程序 ****\n");
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
				(*MenuFp[MenuItem])(a, &n);
		}
	}

	return 0;
}
/*
12
7 3 6 22 4 2 8 12 5 11 18 43
*/
