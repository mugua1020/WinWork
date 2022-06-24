/*	File: exe4-5-3���ֲ���.c
	��ϰ��4-5-3�����ֲ���
				biSearch()	�ǵݹ�
				biSearchR()	�ݹ�	*/

#include <stdio.h>
#include <stdlib.h>
#define M 20
void biSearch(int *a, int begin, int end, int key)
{
	int  mid;
	while(begin <= end)
	{
		if(key <a[begin] || key > a[end])	/* ����ʧ��			*/
			break;
		mid = (begin + end) / 2 ;
/*	if debug
*/
		printf("b=%d e=%d m=%d key=%d\n", begin, end, mid, key);
		if(key == a[mid]) 					/* ���ҳɹ�			*/
		{
			printf("a[%d]=%d\n", mid, key); /* ���a[mid], mid	*/
			return;
		}
		else if(key > a[mid])
			begin = mid + 1; 				/* ����[mid+1, end]	*/
		else if(key < a[mid])
			end = mid;	 					/* ����[begin, mid]	*/
	}
	printf("can not found %d\n", key);		/* ���ʧ����Ϣ		*/
}
void biSearchR(int *a, int begin, int end, int key)
{
	int mid;
	if(key < a[begin] || key > a[end])		/* ����ʧ��			*/
	{
		printf("can not found %d\n", key);
		return;
	}
	mid = (begin + end) / 2;
/*	if debug
*/
	printf("b=%d e=%d m=%d key=%d\n", begin, end, mid, key);
	if(key == a[mid])						/* ���ҳɹ�			*/
	{
		printf("a[%d]=%d\n", mid, key);
		return;
	}
	else if(key > a[mid])					/* ����[mid+1, end]	*/
		biSearchR(a, mid+1, end, key);
	else if(key < a[mid])					/* ����[begin, mid]	*/
		biSearchR(a, begin, mid, key);
}
int main()
{
	int a[M];
	int len, i, key;
	printf("number and array: ");
	scanf("%d", &len);
	for(i=0; i< len; i++)
		scanf("%d", &a[i]);
	printf("data to search : ");
	scanf("%d", &key);
	biSearch(a, 0, len-1, key); 
	biSearchR(a, 0, len-1, key); 
	system("pause");
}
/*
9
10 22 33 41 55 69 70 80 91
*/
