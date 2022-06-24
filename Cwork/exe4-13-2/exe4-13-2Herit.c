/*	File: exe4-13-2Herit.c
	相关文件：exe4-13-2家谱图.c	*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN struct inheritor
#define	M		10		/* 队列容量			*/
#define	MAX	 	M-1 	/* 队尾指针的最大值 */
#define	MIN	 	0   	/* 队首指针的最小值	*/
#define	EMPTY	MIN-1	/* 空队指针值		*/
IN					/* 继承人(inheritor)信息*/
{
	int	n;			/* 继承人(number)		*/
	int g;			/* 继承顺序(generation)	*/
	int p;			/* 父母(parent)			*/
	IN *next;
};
IN *Head;			/* 继承人链表			*/
IN *Clan;			/* 家谱图链表			*/
IN *Q[M];			/* 循环队列指针数组		*/
int	Top=EMPTY; 		/* 队首指针，初始为空队	*/
int	Tail=EMPTY; 	/* 队尾指针，初始为空队	*/
void error(char *);

void output(IN*,char*);

void enQueue(IN *key)
{
	if((Tail+1) % M == Top)	
		error("上溢出(overflow)"); 	/* 上溢出(overflow)	*/
	if(Top<EMPTY || Top>MAX || Tail<EMPTY || Tail>MAX)
		error("非法进队"); 			/* 非法				*/
	/* 更新队列指针			*/
	if(Tail==EMPTY&&Top==EMPTY)
	{
		Tail=0;
		Top=0;
	}
	else
	{
		Tail = (Tail+1)%M;
	}
	key->next=NULL;
	
	Q[Tail] = key;					/* 包括正常情况		*/
}
IN *deQueue(void)
{
	IN *key;
	if(Top<EMPTY || Top>MAX || Tail<EMPTY || Tail>MAX)
		error("非法出队");			/* 非法				*/
	if(Top == EMPTY)
		return(NULL); 				/* 下溢出(underflow)*/
	/* 更新队列指针			*/
	key= Q[Top];
	if(Top==Tail&&Tail>EMPTY)
		Top=Tail=EMPTY;
	else
		Top = (Top+1)%M;
	
	return(key); 
}
void prtClan(IN *clan)	/* 打印家谱图pedigree of clan	*/
{
	int i,num;
	if(clan != Clan)
	{
		num=clan->next->g - clan->g;
		if(num>=1)
		{
			for(i=1; i<num; i++)
				printf("########  ");
			printf("%2d,%2d,%2d  ", 
	 		clan->next->n, clan->next->g, clan->next->p);
		}
		else
		{
			printf("\n");
			for(i=1; i<clan->next->g;i++)
			printf("########  ");
			printf("%2d,%2d,%2d  ", 
	 		clan->next->n, clan->next->g, clan->next->p);
		}
	}
	else
	{
		for(i=1; i<clan->next->g; i++)
			printf("########  ");
		printf("%2d,%2d,%2d  ", 
	 		clan->next->n, clan->next->g, clan->next->p);
	}
	// int i;
	// if(clan->next->next && clan->next->g <= clan->next->next->g)
	// {
	// 	for(i=1; i<clan->next->g; i++)
	// 		printf("########  ");
	// }
	// printf("%2d,%2d,%2d  ", 
	// 		clan->next->n, clan->next->g, clan->next->p);
	// if(clan->g <= clan->next->g)
	// 	printf("\n");
}
void GetClan(IN *clan)	/* 遍历家谱图pedigree of clan	*/
{
	if(clan->next == NULL)
		return;
	prtClan(clan);
	GetClan(clan->next);
}

void GetHerit(void)		/* 获取家谱链表Clan		*/
{
	int h=1, g=1;
	IN *node, *key, *prev;
	/* 在继承人链表Head中删除遗孀(第一继承人)，进队	*/
	for(prev=Head; prev->next; prev=prev->next)
		if(prev->next->g == g)
		{
			key = prev->next;
			prev->next = key->next;
			enQueue(key);
			break;
		}
	/* 只要队非空，循环				*/
	while((key = deQueue()) != NULL)
	{
		printf("ddddd%d\n",key->n);
		/* 从继承人链表Head中删除key的所有子女，逐个进队*/
		for(prev=Head;prev->next!= NULL;)
		{
			while( prev->next!= NULL && prev->next->p==key->n )
		{
			node=prev->next;
			prev->next=node->next;
			enQueue(node);
		}
		if(prev->next!=NULL)
			prev=prev->next;
		
		}
		
		
		
		/* 将key插入家谱链表Clan	*/
		for(prev=Clan; prev->next; prev=prev->next)
			if(prev->next->n == key->p)
			{
				
				break;
			}
				

		
		

		if(prev->next == NULL)
		Clan->next=key;
		else
		{
			node=prev->next;
			key->next=node->next;
			node->next=key;
			output(Clan->next, "Clan");
		}
		
	}
}
