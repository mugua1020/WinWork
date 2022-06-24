

#include <stdio.h>
#include <stdlib.h>
#define S struct student

char* strcpy(char* des,const char* sourse)
{
    if(des==NULL||sourse==NULL)
        return NULL;
    char* res=des;
    while((*des++=*sourse++)!='\0');
    return res;
}

int strcmp (const char *str1,const char *str2)
{
    while (*str1 && *str2 && (*str1 == *str2))
    {
        str1++;
	str2++;
    }
    return *str1 - *str2;
}


//int strlen(const char *str)
int my_strlen(const char *str)//we can not use strlen name
{
	int ret=0;
	while (*str)
	{
		ret++;
		str++;
	}
	return ret;
}


S 
{
	char * name;
	float  math, phys;
	S *  next;
};
S *First = NULL;
void error(char *format, char *string)
{
	fprintf(stderr, format, string);
	exit(0);
}
void input(char *file)
{
	FILE *fopen(), *fp;
	S *student;
	char name[20];
	float math, phys;
	fp = fopen(file, "r");
	if(fp == NULL)
		error("cannot open file %s\n", file);
	while(fscanf(fp, "%s%f%f", name, &math, &phys) == 3)
	{
		student = (S*)malloc(sizeof(S));
		if(student == NULL)
			error("no space for student\n", NULL);
		student->name = (char*)malloc(my_strlen(name)+1); //pay attention to it
		if(student->name == NULL)
			error("no space for name\n", NULL);
		strcpy(student->name, name);
		//student->name = name;  //no

		student->math = math;
		student->phys = phys;
		student->next = First; First = student;
	}
}
int getscore(char *name, float *sum,float *average )
{
	S *student;
	for(student=First; student!=NULL; student=student->next)
	if(strcmp(name, student->name) == 0)
	//if(name == student->name)	//no
	{
		*sum = student->math +student->phys;
		*average = *sum/2;
		return(0);
	}
	return(-1);
}
int getnum()
{
	int number = 0;
	S *s;
	for( s = First; s!= NULL; s= s->next )
		number++;
	return(number);
}
int main()
{
	char name[20], task[10];
	int number, found;
	float sum, average;
	input("student.txt");
	printf("what task [n|s(number or student)]? ");
	while(scanf("%s", task) > 0)
	{
		switch(task[0])
		{
			case 'n':  number= getnum();
				printf("total student number = %d\n", number);
				break;
			case 's': printf("who? ");
				scanf("%s", name);
				found= getscore(name, &sum, &average);
				if(found == 0)
				{
					printf("student: %s  ",name);
					printf("sum= %8.3f  ", sum);
					printf("average= %8.3f\n", average);
				}
				else
					printf("not found %s\n", name);
				break;
			default:  printf("invalid task\n");
					system("pause");
					exit(0);
		}
		printf("what task [n|s(number or student)]? ");
	}
}
/*
what task [n|s(number or student)]? n
total student number = 32
what task [n|s(number or student)]? s
who? me12
student: me12  sum=  166.500  average=   83.250
what task [n|s(number or student)]? s
who? me43
student: me43  sum=  169.000  average=   84.500
what task [n|s(number or student)]? s
who? me01
not found me01
what task [n|s(number or student)]? c
invalid task
*/
