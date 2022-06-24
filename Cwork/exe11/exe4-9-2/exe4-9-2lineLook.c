/*	File: exe4-9-2lineLook.c
	【习题4-9-2】顺序存储的线性表基本操作程序
	相关文件：exe4-9-2lineListMain.c
			  exe4-9-2lineListSub.c	*/

#include <stdio.h>
#include <stdlib.h>
#define	M   1000
void error(char *);

void Look(int *a, int *n)
{
	int j, key;
	printf("**** 请输入结点值 ****\n");
	scanf("%d", &key);
	/* 根据用户输入的结点值key，输出前件prev和后件succ	*/
	for(j=0;j<*n;j++)
	{
		if(a[j]==key)
		{
			printf("key: node(%d) = %d\n",j,a[j]);
			printf("prev:node(%d) = %d\n",j-1,a[j-1]);
			printf("succ:node(%d) = %d\n",j+1,a[j+1]);
		}
	}
	
	printf("**** 查找前件后件已完成 ****\n");
}
