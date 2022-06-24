/*	File: exe4-6-5合并排序.c
	【习题4-6-5】顺序存名合并排序	*/

#include <stdio.h>
#include <stdlib.h>
#define M 20
void merge(int *a, int begin, int mid, int end)
{ 		  
	int left=begin, right=mid+1, i;
	int b[M];
	for(i=begin; i<=end; i++)
		b[i] = a[i];
	printf("begin=%d mid=%d end=%d left=%d right=%d\n", 
		begin, mid, end, left, right);
	for(i=begin; i<=end; i++)
		printf("%d ", b[i]);
	printf("\n");
	for(i=begin; i<=end; i++)
	{
		if(right > end)
			a[i] = b[left++];
		else if(left > mid)
			a[i] = b[right++];
		else if(b[left] < b[right])
			a[i] = b[left++];
		else
			a[i] = b[right++];
	}
	for(i=begin; i<=end; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void divide(int *a, int begin, int end)
{
	if(begin < end)
	{
		int mid = (begin + end) / 2;
		divide(a, begin, mid);
		divide(a, mid+1, end);
		merge(a, begin, mid, end);
	}
}
int main()
{
	int a[M];
	int n, i;
	printf("**** 请输入结点数和各个结点值 ****\n");
	scanf("%d", &n);
	for(i=0; i< n; i++)
		scanf("%d", &a[i]);
	divide(a, 0, n-1); 
	printf("**** 排序结果 ****\n");
	for(i=0; i< n; i++)
		printf("%d ", a[i]);
	printf("\n");
	system("pause");
}
/*
8
5 2 7 3 1 6 8 4
9
5  2  9  1  8  3  7  4  6
11
5 2 11 9 7 3 1 6 8 10 4
*/
