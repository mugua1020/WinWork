/*	File: cas4-34MakeTree.c
	【例4-34】输入括号表示的五次树	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define  TRINODE  struct  trinode
#define  BINODE   struct  binode
#define N   3
#define M 	60
TRINODE
{
	int key;
	TRINODE *sub[N];
};
char String[M];     /* 输入字符串	*/
int  Ptr=0;			/* 字符数组指针	*/
TRINODE *RootT;

void error(char *string)
{
	printf("%s\n", string);
	exit(0);
}
void input(void)
{
	int i=0, c;  
	FILE *fp;
	char filename[M];
	printf("输入哪个文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	while( (c=fgetc(fp)) != EOF)
	{
		if(!isspace(c))			/* 是空字符?	*/
			String[i++] = c;	/* 将空字符滤去 */
	}
	String[i] = '\0';
	printf("输入的五次树: \n%s\n", String); 
}
int GetKey(char *key)
{
	if(!isalpha(*key = String[Ptr]))
		return(0);  /* 取结点值成功 */
	Ptr++;
	return(1); 		/* 取结点值成功 */
}
int GetSymbol(char symbol) 
{
	if(String[Ptr] != symbol)
		return(0);  /* 取符号失败	*/
	Ptr++;
	return(1); 		/* 取符号成功	*/
}
TRINODE *newNode(char key)
{
	int j;
	TRINODE *node;
	node = (TRINODE *)(malloc(sizeof(TRINODE)));
	if(node == NULL)
		error("no space!"); 
	node->key = key;
	for(j=0; j<N; j++)
		node->sub[j] = NULL;
	return(node);
}
void MakeNode(TRINODE *root)
{
	char key;
	if(!GetSymbol('('))				/* 1. 取左括号	*/
	    return;						/* 空树			*/
	if(!GetKey(&key))				/* 2. 取子结点1	*/
		error("no node !"); 
	MakeNode(root->sub[0] = newNode(key));
	if(GetSymbol(','))				/* 3. 取逗号	*/
	{
		if(GetKey(&key))			/* 4. 取子结点2	*/
		{  
			MakeNode(root->sub[1] = newNode(key));
			if(GetSymbol(','))		/* 5. 取逗号	*/
				if(GetKey(&key))	/* 6. 取子结点3	*/
					MakeNode(root->sub[2] = newNode(key));
		}
	}
	if(!GetSymbol(')'))				/* 7. 取右括号	*/
		error("missing ) !"); 
}
void MakeTree()
{
	char key;
	if(GetKey(&key))	 /* 获取根结点值	*/
	{	
		RootT = newNode(key);
		MakeNode(RootT);
	}
	else
		error("Empty tritree!"); 
} 
