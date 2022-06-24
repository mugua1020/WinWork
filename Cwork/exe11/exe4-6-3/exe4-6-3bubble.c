/*	File: exe4-6-3bubble.c
	【习题4-6-3】顺序存储冒泡排序	*/

// 原因简单分析：Windows(中文)默认的字符集是Windows-936(GBK)，
// 而GCC编译器默认编译的时候是按照UTF-8解析的，当未指定字符集时
// 一律当作UTF-8进行处理，于是造成乱码
//gcc .\exe4-6-3bubble.c -fexec-charset=gbk -o exe4-6-3bubble.exe


//示例有一点问题，这里略作修改
#include <stdio.h>
#include <stdlib.h>
void bubble(int a[], int n)
{
	int i,j,temp,flag;
	for(i=0;i<n-1;i++)
	{
		for(j=0,flag =0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				flag =1;
				temp = a[j];
				a[j] =a[j+1];
				a[j+1] =temp;
			}
		}
		if(flag==0)
		break;

		for(j=0;j<n-1;j++)
		printf("%d ",a[j]);
		printf("%d\n",a[n-1]);
		
		
	}
		
}
void main()
{
	int a[20], n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("冒泡排序\n");
	bubble(a, n);
	system("pause");
}
/*
输入数据1
5
1 7 8 4 5
冒泡排序
1 7 4 5 8
1 4 5 7 8


输入数据2
9
2 3 4 1 5 6 7 8 9
冒泡排序
2 3 1 4 5 6 7 8 9
2 1 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
*/