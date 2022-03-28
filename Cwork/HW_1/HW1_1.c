#include<stdio.h>   
#include<string.h> 
 
int main()
{
    
    const int  N=1024*1009 +792;  // IM以内，不然提示 stack overflow
 
    char   buf[N];
    memset(buf, 'A', N);
    buf[N - 2] = 'X';
    buf[N - 1] = '\0';
   // printf("%s", buf);
 
    printf("ok? have a try\n");
    return 0;

}