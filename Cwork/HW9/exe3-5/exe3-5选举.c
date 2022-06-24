

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define C struct candidate
#define ERROR(S) 	{printf(S); exit(0);}//  ;
C
{
	char  name[20];
	int   code, vote;
	C *next; 
};
C  * Head = NULL;
int getCandidate(FILE * fp)
{ 
	C * candidate;
	char name[20];
	int nCandidate = 0, code;
	while(fscanf(fp, "%s%d", name, &code) != EOF)
	{
		if( (candidate = (C*)malloc(sizeof(C)))==NULL ) 
			ERROR("no space for candidate\n"); 
		strcpy(candidate->name, name);
		candidate->code = code;
		candidate->vote = -1;
		candidate->next = Head; Head= candidate;
		nCandidate ++;
	}
	return(nCandidate ); 
}
void getVote(FILE * fp, int *nSenator)
{
	C * candidate;
	int code;
	fscanf(fp, "%d", nSenator ); 
	while(fscanf(fp, "%d", &code) != EOF)
	{
		for( candidate=Head;candidate!=NULL;candidate=candidate->next ) 
		if(code == candidate->code)
		{
			candidate->vote += (candidate->vote <0)? 2:1 ; 
			break;
		}
	}
}
C * electSenator(C * candidate)
{ 
	int maxVote = 0;
	C * senator;
	senator = NULL;
	for(;candidate!=NULL;candidate=candidate->next ) 
		if(candidate->vote > maxVote)
		{
			senator = candidate; 
			maxVote = senator->vote;
		}
	if( senator != NULL )
		senator->vote = -senator->vote ;
	else
		ERROR("cannot elect senator.\n"); 
	return(senator);
}
int main()
{
	int i, nSenator, nCandidate;
	C * senator;
	FILE *fpVote, *fpCandidate;
	if((fpVote = fopen("vote.txt", "r")) == NULL ||
		 !(fpCandidate = fopen("candidate.txt", "r")) )
		ERROR("cannot open files.\n"); 
	nCandidate = getCandidate(fpCandidate) ;
	getVote(fpVote, &nSenator);
	if(nSenator >= nCandidate)
		ERROR("invalid election\n"); 
	printf("nS=%d nC=%d\n", nSenator, nCandidate);
	for(i=0; i<nSenator; i++)
		if((senator = electSenator(Head)) != NULL)
			printf("NAME=%-20s CODE=%-5d VOTE=%d\n", senator->name, senator->code, -senator->vote );
	system("pause");
}
