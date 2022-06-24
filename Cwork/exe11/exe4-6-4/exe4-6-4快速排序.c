/*	File: exe4-6-4快速排序.c
	【习题4-6-4】顺序存储快速排序	*/

#include <stdio.h>
#include <stdlib.h>
#define M 10
int n;
void prt(int *a)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int move(int *a, int left, int right)
{ 		  
	int key;
	key = a[left];
	while(left < right)
	{
		while(left < right && key < a[right])
			right--;
		a[left] = a[right];
		while(left < right && key > a[left])
			left++;
		a[right] = a[left];
	}
	a[left] = key;
/*	if debug
	printf("left[%d]=%d right[%d]=%d\n", left, a[left], right, a[right]);
*/
	prt(a);
	return(left);
}
void quick(int *a, int left, int right)
{
	int m;
	if(left >= right)
		return;
	m = move(a, left, right);
	quick(a, left, m-1);
	quick(a, m+1, right);
}
int main()
{
	int a[M];
	int i;
	printf("**** 请输入结点数和各个结点值 ****\n");
	scanf("%d", &n);
	for(i=0; i< n; i++)
		scanf("%d", &a[i]);
	quick(a, 0, n-1); 
	printf("**** 快速排序结果 ****\n");
	prt(a);
	system("pause");
}
/*
**** 请输入结点数和各个结点值 ****
8
5 2 7 3 1 4 8 6
4 2 1 3 5 7 8 6
3 2 1 4 5 7 8 6
1 2 3 4 5 7 8 6
1 2 3 4 5 7 8 6
1 2 3 4 5 6 7 8
**** 快速排序结果 ****
1 2 3 4 5 6 7 8

**** 请输入结点数和各个结点值 ****
10
5 1 0 7 9 2 3 8 6 4
4 1 0 3 2 5 9 8 6 7
2 1 0 3 4 5 9 8 6 7
0 1 2 3 4 5 9 8 6 7
0 1 2 3 4 5 9 8 6 7
0 1 2 3 4 5 7 8 6 9
0 1 2 3 4 5 6 7 8 9
**** 快速排序结果 ****
0 1 2 3 4 5 6 7 8 9
*/
