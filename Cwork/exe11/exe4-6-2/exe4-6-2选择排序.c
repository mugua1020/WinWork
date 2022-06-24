/*	File: exe4-6-2选择排序.c
	【习题4-6-2】顺序存储选择排序	*/

#include <stdio.h>
#include <stdlib.h>
#define M 10
void prt(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void select(int *a, int n)
{ 		  
	int i, j, min, tmp;
	for(i=0; i<n; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
			if(a[min] > a[j])
				min = j;
		tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
	prt(a, n);
/*	if debug
*/
	}
}
int main()
{
	int a[M];
	int i, n;
	printf("**** 请输入结点数和各个结点值 ****\n");
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	select(a, n); 
	printf("**** 排选择序结果 ****\n");
	prt(a, n);
	system("pause");
}

/**** 请输入结点数和各个结点值 ****
8
5 2 7 3 1 4 8 6
1 2 7 3 5 4 8 6
1 2 7 3 5 4 8 6
1 2 3 7 5 4 8 6
1 2 3 4 5 7 8 6
1 2 3 4 5 7 8 6
1 2 3 4 5 6 8 7
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7 8
**** 选择排序结果 ****
1 2 3 4 5 6 7 8

**** 请输入结点数和各个结点值 ****
7
5 7 3 1 4 8 6
1 7 3 5 4 8 6
1 3 7 5 4 8 6
1 3 4 5 7 8 6
1 3 4 5 7 8 6
1 3 4 5 6 8 7
1 3 4 5 6 7 8
1 3 4 5 6 7 8
**** 选择排序结果 ****
1 3 4 5 6 7 8

10
5 1 0 7 9 2 3 8 6 4
**** 选择排序结果 ****
0 1 2 3 4 5 6 7 8 9
*/
