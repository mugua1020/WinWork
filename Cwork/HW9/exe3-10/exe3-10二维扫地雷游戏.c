/*	File: exe3-10二维扫地雷游戏.c	*/


// 在编译参数中增加以下两条指令：

// -fexec-charset=gbk

// -finput-charset=gbk

// 原因简单分析：Windows(中文)默认的字符集是Windows-936(GBK)，
// 而GCC编译器默认编译的时候是按照UTF-8解析的，当未指定字符集时
// 一律当作UTF-8进行处理，于是造成乱码
//gcc .\exe3-10二维扫地雷游戏.c -fexec-charset=gbk -o exe3-10.exe


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4		/* 布雷区域 = N x N	*/
void laymine(int mine[][N], int n, int allMine)
{
	int j, k, random, m;
	time_t w;
	for(j=0; j<n; j++)
	for(k=0; k<n; k++)
		mine[j][k] = 0;
	srand((unsigned int)time(&w));
	for(m=0; m<allMine; )
	{
		/* complete code here	*/
		random = rand() % n*n +1;
		if(mine[random/n-1][random%n-1] == 0)
		{
			mine[random/n-1][random%n-1] = random;
			m++;
		}
	
	}
}
void sweepmine(int mine[][N], int n, int *allMine)	/* 玩家扫雷函数	*/
{
	int j, k;
	printf("请扫雷[第1-%d行第1-%d列]：", n, n);
	scanf("%d%d", &j, &k);
	/* complete code here	*/
	if(j>0 && j<= n && k>0 && k<= n && mine[j-1][k-1])
	{
		mine[j-1][k-1] =0;
		(*allMine)--;
	}



}

void prt(int mine[][N], int n, int allMine)
{
	short j, k;
	printf("扫雷结束。剩余%d个地雷，分布为:\n", allMine);
	for(j=0; j<n; j++)
	{
		for(k=0; k<n; k++)
			printf("%3d", mine[j][k]);
		printf("\n");
	}
}
void main()
{
	int mine[N][N], n=N, allMine=n, tryTime, allTime;
	printf("****欢迎尝试二维扫地雷游戏****\n\n");
	while(allMine > 2)
	{
		printf("你想布几个地雷?[2-%2d个为有效,否则表示结束游戏]: ", n*n-3);
		scanf("%d", &allMine);
		if(allMine < 2 || allMine > n*n-3)
			break;
		allTime = allMine + 2;	/* 最多扫雷次数=地雷总数+2	*/
		tryTime = 0;
		laymine(mine, n, allMine);
		while(allMine > 0 && tryTime < allTime)
		{
			printf("现有%2d个地雷. ", allMine);
			printf("你还有%2d次机会. ", allTime-tryTime);
			sweepmine(mine, n, &allMine);
			++tryTime;
		}
		prt(mine, n, allMine);
		allMine = n;
		printf("\n欢迎再来一次\n");
	}
	printf("\n****欢迎下次再来尝试扫地雷游戏****\n\n");
	system("pause");
}
/*
****欢迎尝试扫地雷游戏****

你想布几个地雷?[2-13个为有效,否则表示结束游戏]: 3
现有 3个地雷. 你还有 5次机会. 请扫雷[第1-4行第1-4列]：1 1
现有 3个地雷. 你还有 4次机会. 请扫雷[第1-4行第1-4列]：1 2
现有 3个地雷. 你还有 3次机会. 请扫雷[第1-4行第1-4列]：1 3
现有 3个地雷. 你还有 2次机会. 请扫雷[第1-4行第1-4列]：1 4
现有 3个地雷. 你还有 1次机会. 请扫雷[第1-4行第1-4列]：2 1
扫雷结束。剩余3个地雷，分布为:
  0  0  0  0
  0  0  7  0
  0 10 11  0
  0  0  0  0

欢迎再来一次
你想布几个地雷?[2-13个为有效,否则表示结束游戏]: 4
现有 4个地雷. 你还有 6次机会. 请扫雷[第1-4行第1-4列]：1 1
现有 4个地雷. 你还有 5次机会. 请扫雷[第1-4行第1-4列]：1 2
现有 3个地雷. 你还有 4次机会. 请扫雷[第1-4行第1-4列]：1 3
现有 3个地雷. 你还有 3次机会. 请扫雷[第1-4行第1-4列]：1 4
现有 3个地雷. 你还有 2次机会. 请扫雷[第1-4行第1-4列]：2 1
现有 2个地雷. 你还有 1次机会. 请扫雷[第1-4行第1-4列]：2 2
扫雷结束。剩余2个地雷，分布为:
  0  0  0  0
  0  0  0  0
  9 10  0  0
  0  0  0  0

欢迎再来一次
你想布几个地雷?[2-13个为有效,否则表示结束游戏]: 0

****欢迎下次再来尝试扫地雷游戏****
*/