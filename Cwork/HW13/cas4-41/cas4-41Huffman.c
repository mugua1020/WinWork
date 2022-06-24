/* File: cas4-41Huffman.c
	【例4-41】哈夫曼编码(Huffman码)生成算法	*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define NODE struct node
NODE
{
	char key;
	int weigh;
	char code[10];
	NODE *next;
	NODE *left, *right;
};
NODE *Head;
int lenCode=0;
void prt()
{
	NODE *node = Head->next;
	for(; node ; node = node->next)
		printf("%c %d ", node->key, node->weigh);
	printf("\n");
}
void prtCode(NODE *node)
{
	int lengh;
	if(node == NULL)
		return;
	if(node->key != '#')
	{
		lengh = strlen(node->code) * node->weigh;
		lenCode += lengh;
		printf("%c %d [%s] %d\n", node->key, node->weigh, node->code, lengh);
	}
	prtCode(node->left);
	prtCode(node->right);
	return;
}
void preOrder(NODE *node)
{
	if(node == NULL)
		return;
	printf("%c %d %s\n", node->key, node->weigh, node->code);
	preOrder(node->left);
	preOrder(node->right);
}
void LeafOrder(NODE *node)
{
	if(node == NULL)
		return;
	if(!node->left && !node->right)
		printf("%c %d %s\n", node->key, node->weigh, node->code);
	LeafOrder(node->left);
	LeafOrder(node->right);
}
void insertNode(NODE *node)
{
	NODE *prev = Head;
	while(prev->next && node->weigh > prev->next->weigh)
		prev = prev->next;
	node->next = prev->next;
	prev->next = node;
}
void MakeTree()
{
	NODE *node;
	while(Head->next->next)
	{
		if((node = (NODE *)malloc(sizeof(NODE))) == NULL)
			exit(0);
		node->left = Head->next;
		Head->next = Head->next->next;
		node->right = Head->next;
		Head->next = Head->next->next;
		node->key = '#';
		node->code[0] = '\0';
		node->weigh = node->left->weigh + node->right->weigh;
		insertNode(node);
		prt();
	}
}
void MakeCode(NODE *node)
{
	if(node == NULL)
		return;
	/*	左右子编码，补齐代码		*/
	int lenth=strlen(node->code);

	if(node->left != NULL)
	{
		strcpy(node->left->code,node->code);
		node->left->code[lenth] = '0';
		node->left->code[lenth+1] = '\0';
		MakeCode(node->left);
	}

	if(node->right != NULL)
	{
		strcpy(node->right->code,node->code);
		node->right->code[lenth] = '1';
		node->right->code[lenth+1] = '\0';
		MakeCode(node->right);
	}



	
	
	
	/*	--------------------------	*/
/*	if debug
	printf("%c %d [%s]\n", node->key, node->weigh, node->code);
*/
}


// gcc .\cas4-41Huffman.c -fexec-charset=gbk -o Huffman.exe
void main()
{
	char key[10];
	int weigh;
	NODE *node;
	FILE *fp;
	char filename[60];
	printf("输入结点文件: ");
	scanf("%s", filename);
	if((fp = fopen(filename, "r")) == NULL)
		exit(0);
	if((Head = (NODE *)malloc(sizeof(NODE))) == NULL)
		exit(0);
	Head->next = NULL;
	Head->key = '-';
	while(fscanf(fp, "%s%d", key, &weigh) == 2)
	{
		if((node = (NODE *)malloc(sizeof(NODE))) == NULL)
			exit(0);
		node->key = key[0];
		node->weigh = weigh;
		node->code[0] = '\0';
		node->left = NULL;
		node->right = NULL;
		insertNode(node);
	}
	prt();
	printf("MakeTree\n");
	MakeTree();
/*	if debug
	printf("preOrder\n");
	preOrder(Head->next);
	printf("MakeCode\n");
*/
	MakeCode(Head->next);
/*	if debug
	printf("LeafOrder\n");
	LeafOrder(Head->next);
*/
	printf("prtCode\n");
	prtCode(Head->next);
	printf("lengh of code = %d\n", lenCode);
	system("pause");
}
/*
node1.txt
A 2 D 4 G 5 O 8
MakeTree
G 5 # 6 O 8
O 8 # 11
# 19
prtCode
O 8 [0] 8
G 5 [10] 10
A 2 [110] 6
D 4 [111] 12
lengh of code = 36

node2.txt
V 1 G 2 L 5 R 6 N 7 E 10
MakeTree
# 3 L 5 R 6 N 7 E 10
R 6 N 7 # 8 E 10
# 8 E 10 # 13
# 13 # 18
# 31
prtCode
R 6 [00] 12
N 7 [01] 14
V 1 [1000] 4
G 2 [1001] 8
L 5 [101] 15
E 10 [11] 20
lengh of code = 73

node3.txt
B 1 Y 3 D 5 H 6 O 8 A 10
MakeTree
# 4 D 5 H 6 O 8 A 10
H 6 O 8 # 9 A 10
# 9 A 10 # 14
# 14 # 19
# 33
prtCode
H 6 [00] 12
O 8 [01] 16
B 1 [1000] 4
Y 3 [1001] 12
D 5 [101] 15
A 10 [11] 20
lengh of code = 79

node4.txt
P 2 F 3 C 4 S 7 O 8 E 10
MakeTree
C 4 # 5 S 7 O 8 E 10
S 7 O 8 # 9 E 10
# 9 E 10 # 15
# 15 # 19
# 34
prtCode
S 7 [00] 14
O 8 [01] 16
C 4 [100] 12
P 2 [1010] 8
F 3 [1011] 12
E 10 [11] 20
lengh of code = 82

node5.txt
P 2 M 3 U 4 H 6 N 8 T 10
MakeTree
U 4 # 5 H 6 N 8 T 10
H 6 N 8 # 9 T 10
# 9 T 10 # 14
# 14 # 19
# 33
prtCode
H 6 [00] 12
N 8 [01] 16
U 4 [100] 12
P 2 [1010] 8
M 3 [1011] 12
T 10 [11] 20
lengh of code = 80

node6.txt
P 2 M 3 U 4 H 6 N 10 T 11
MakeTree
U 4 # 5 H 6 N 10 T 11
H 6 # 9 N 10 T 11
N 10 T 11 # 15
# 15 # 21
# 36
prtCode
H 6 [00] 12
U 4 [010] 12
P 2 [0110] 8
M 3 [0111] 12
N 10 [10] 20
T 11 [11] 22
lengh of code = 86
*/