/*	File: exe4-6-2ѡ������.c
	��ϰ��4-6-2��˳��洢ѡ������	*/

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
	printf("**** �����������͸������ֵ ****\n");
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	select(a, n); 
	printf("**** ��ѡ������ ****\n");
	prt(a, n);
	system("pause");
}

/**** �����������͸������ֵ ****
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
**** ѡ�������� ****
1 2 3 4 5 6 7 8

**** �����������͸������ֵ ****
7
5 7 3 1 4 8 6
1 7 3 5 4 8 6
1 3 7 5 4 8 6
1 3 4 5 7 8 6
1 3 4 5 7 8 6
1 3 4 5 6 8 7
1 3 4 5 6 7 8
1 3 4 5 6 7 8
**** ѡ�������� ****
1 3 4 5 6 7 8

10
5 1 0 7 9 2 3 8 6 4
**** ѡ�������� ****
0 1 2 3 4 5 6 7 8 9
*/
