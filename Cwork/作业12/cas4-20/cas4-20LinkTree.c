/* File: cas4-20LinkTree.c
	【例4-20】输入括号表示的五次树
	实现链接存储五次树的前序遍历,后序遍历和后序遍历
	相关文件：cas4-20MakeTree.c	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define NODE struct node
#define	M		20		/* 队列容量			*/
#define	MAX	 	M-1 	/* 队尾指针的最大值 */
#define	MIN	 	0   	/* 队首指针的最小值	*/
#define	EMPTY	MIN-1	/* 空队指针值		*/
#define N   5
NODE
{
	int num;
	NODE *sub[N];
};
NODE *Q[M];			/* 循环队列指针数组		*/
int	Top=EMPTY; 		/* 队首指针，初始为空队	*/
int	Tail=EMPTY; 	/* 队尾指针，初始为空队	*/

NODE *Root=NULL;

/* MakeLnkTree.c 中定义的函数	*/
void input(void);
void MakeTree(void);
void error(char *);

void enQueue(NODE *node)
{
	if((Tail+1) % M == Top)	
		error("上溢出(overflow)"); 	/* 上溢出(overflow)	*/
	if(Top<EMPTY || Top>MAX || Tail<EMPTY || Tail>MAX)
		error("非法进队"); 			/* 非法				*/
	/* 更新队列指针			*/
	Tail = (Tail + 1) % M; 
	if(Top == EMPTY)
		Top = Tail;
	Q[Tail] = node;					/* 包括正常情况		*/
}
NODE *deQueue(void)
{
	NODE *node;
	if(Top<EMPTY || Top>MAX || Tail<EMPTY || Tail>MAX)
		error("非法出队");			/* 非法				*/
	if(Top == EMPTY)
		return(NULL);
	node = Q[Top];
	/* 更新队列指针			*/
	if(Top != Tail)					/* 正常出队			*/
		Top = (Top + 1) % M;
	else  							/* 出空：成为空队	*/
		Top = Tail = EMPTY;
	return(node); 
}
/* 前序遍历函数preOrder()		*/
void preOrder(NODE *node)
{
	int i;
	if(!node)
		return;
	printf("%d ", node->num); 
  	for(i=0; i<N; i++)
		preOrder(node->sub[i]);
}
/* 后序遍历函数postOrder()	*/
void postOrder(NODE *node)
{
	int i;
	if(!node)
		return;
  	for(i=0; i<N; i++)
		postOrder(node->sub[i]);
	printf("%d ", node->num); 
}
/* 层次遍历函数postOrder()	*/
void levelOrder(NODE *node)
{
	int i;
	if(!node)
		return;
	enQueue(node);
  	while(node = deQueue())
	{
		printf("%d ", node->num); 
		for(i=0; i<N; i++)
			if(node->sub[i])
				enQueue(node->sub[i]);
		
	}
}
void main()
{
	/* 1. 输入字符串 */
	printf("请输入括号表示的五次树"); 
	printf("(以控制符^Z+换行符为结束):\n"); 
	input();
	/* 2. 生成树 */
	MakeTree();
	/* 3. 树的前序后序遍历 */
	printf("前序遍历: \n"); 
	preOrder(Root);
	printf("\n");
	printf("后序遍历: \n"); 
	postOrder(Root);
	printf("\n");
	printf("层次遍历: \n"); 
	levelOrder(Root);
	printf("\n");
	system("pause");
}
/*  运行示例1
请输入括号表示的五次树(以控制符^Z+换行符为结束):
5 (7, 12(4, 8,  19, 11) ,
		30 ,2 ,13(32
	,40(  3,17, 23) ) )

输入的五次树:
5(7,12(4,8,19,11),30,2,13(32,40(3,17,23)))
前序遍历:
5 7 12 4 8 19 11 30 2 13 32 40 3 17 23
后序遍历:
7 4 8 19 11 12 30 2 32 3 17 23 40 13 5
层次遍历:
5 7 12 30 2 13 4 8 19 11 32 40 3 17 23
*/

/*  运行示例2
请输入括号表示的五次树(以控制符^Z+换行符为结束):
27  (14, 48 ,19 , 16( 52
	,30 (22, 20), 13),
	17 ( 23, 40, 73 ,35)  )

输入的五次树:
27(14,48,19,16(52,30(22,20),13),17(23,40,73,35))
前序遍历:
27 14 48 19 16 52 30 22 20 13 17 23 40 73 35
后序遍历:
14 48 19 52 22 20 30 13 16 23 40 73 35 17 27
层次遍历:
27 14 48 19 16 17 52 30 13 23 40 73 35 22 20
*/
