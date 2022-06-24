/*	File: exe4-13-2家谱图.c
	相关文件：exe4-13-2Herit.c	*/




//	 gcc .\exe4-13-2Herit.c .\exe4-13-2家谱图.c -fexec-charset=gbk -o  Herit.exe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN struct inheritor
IN					/* 继承人(inheritor)信息*/
{
	int	n;			/* 继承人(number)		*/
	int g;			/* 继承顺序(generation)	*/
	int p;			/* 父母(parent)			*/
	IN *next;
};
IN *Head;			/* 继承人链表		*/
IN *Clan;			/* 家谱链表			*/
int Heritage;		/* 遗产(亿元)		*/
int maxGen=0;		/* 继承人代数		*/
int numGen=0;		/* 继承人人数		*/
void GetHerit(void);
void GetClan(IN *);

void error(char *error_msg)
{
	printf("**** %s ****\n", error_msg);
	exit(0);
}

void input(void)
{
	int	n, g, p;
	IN *node;
	FILE *fp;
	char filename[60];
	printf("输入哪个文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		error("cannot open file");
	fscanf(fp, "%d", &Heritage);
	Heritage *= 10000;
	while(fscanf(fp, "%d%d%d", &n, &g, &p) == 3)
	{
		node = (IN *)malloc(sizeof(IN));
		if(node == NULL)
			error("no space");
		node->n = n;
		node->g = g;
		node->p = p;
		node->next = Head->next;
		Head->next = node;
		numGen ++;
		if(g > maxGen)
			maxGen = g;
	}
}
void output(IN *head, char *title)
{
	IN *node = head;
	if(node == NULL)
		return;
	output(node->next, title);
	printf("%s: n=%-4dg=%-4df=%-4d\n", title,
			node->n, node->g, node->p);
}
void main()
{
	Head = (IN *)malloc(sizeof(IN));
	if(Head == NULL)
		error("no space");
	Head->next = NULL;
	Clan = (IN *)malloc(sizeof(IN));
	if(Clan == NULL)
		error("no space");
	Clan->next = NULL;
	input(); 
/*	if debug
	output(Head->next, "Heritor");		*/
	printf("\n####\t%d代 %d人 继承%d万元遗产\n", 
			maxGen, numGen, Heritage);
	GetHerit();		/* 获取家谱链表Clan	*/
//	if debug
//	output(Clan->next, "Clan");			
	printf("##\t家谱图: n, g, p\t\t  ##\n");
	printf("##\t(继承人, 继承顺序, 父母)  ##\n");
	GetClan(Clan);	/* 遍历家谱图clan	*/
	system("pause");
}
/*
输入哪个文件: Herit.txt
####    3代 9人 继承500000万元遗产
##      家谱图: n, g, p           ##
##      (继承人, 继承顺序, 父母)  ##
14, 1, 0  12, 2,14  11, 3,12
########  ########  13, 3,12
########  16, 2,14
########  20, 2,14  15, 3,20
########  ########  17, 3,20
########  ########  18, 3,20

输入哪个文件: Herit2.txt
##      家谱图: n, g, p           ##
##      (继承人, 继承顺序, 父母)  ##
24, 1, 0  11, 2,24  12, 3,11  19, 4,12  16, 5,19
########  ########  ########  ########  27, 5,19
########  ########  ########  29, 4,12  25, 5,29
########  ########  18, 3,11  37, 4,18  22, 5,37
########  ########  21, 3,11  20, 4,21  13, 5,20
########  ########  ########  31, 4,21
########  ########  35, 3,11
########  28, 2,24  15, 3,28
########  ########  17, 3,28  30, 4,17  14, 5,30
########  ########  ########  33, 4,17
########  ########  39, 3,28  34, 4,39  38, 5,34
########  32, 2,24  26, 3,32  36, 4,26  23, 5,36
*/
