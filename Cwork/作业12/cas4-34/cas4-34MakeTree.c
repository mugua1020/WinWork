/*	File: cas4-34MakeTree.c
	����4-34���������ű�ʾ�������	*/

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
char String[M];     /* �����ַ���	*/
int  Ptr=0;			/* �ַ�����ָ��	*/
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
	printf("�����ĸ��ļ�: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	while( (c=fgetc(fp)) != EOF)
	{
		if(!isspace(c))			/* �ǿ��ַ�?	*/
			String[i++] = c;	/* �����ַ���ȥ */
	}
	String[i] = '\0';
	printf("����������: \n%s\n", String); 
}
int GetKey(char *key)
{
	if(!isalpha(*key = String[Ptr]))
		return(0);  /* ȡ���ֵ�ɹ� */
	Ptr++;
	return(1); 		/* ȡ���ֵ�ɹ� */
}
int GetSymbol(char symbol) 
{
	if(String[Ptr] != symbol)
		return(0);  /* ȡ����ʧ��	*/
	Ptr++;
	return(1); 		/* ȡ���ųɹ�	*/
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
	if(!GetSymbol('('))				/* 1. ȡ������	*/
	    return;						/* ����			*/
	if(!GetKey(&key))				/* 2. ȡ�ӽ��1	*/
		error("no node !"); 
	MakeNode(root->sub[0] = newNode(key));
	if(GetSymbol(','))				/* 3. ȡ����	*/
	{
		if(GetKey(&key))			/* 4. ȡ�ӽ��2	*/
		{  
			MakeNode(root->sub[1] = newNode(key));
			if(GetSymbol(','))		/* 5. ȡ����	*/
				if(GetKey(&key))	/* 6. ȡ�ӽ��3	*/
					MakeNode(root->sub[2] = newNode(key));
		}
	}
	if(!GetSymbol(')'))				/* 7. ȡ������	*/
		error("missing ) !"); 
}
void MakeTree()
{
	char key;
	if(GetKey(&key))	 /* ��ȡ�����ֵ	*/
	{	
		RootT = newNode(key);
		MakeNode(RootT);
	}
	else
		error("Empty tritree!"); 
} 
