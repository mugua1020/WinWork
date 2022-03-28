#include<stdio.h>

int f(int n)
{
    if(n==0 || n== 1)
    return 1;
    else
    {
        int temp[100][100];
        return f(n-1) + f(n-2);
    }
    

}

int main()
{
    const int N=1000;
    int i = f(N);

    printf("%d", i);

    return 0;

}

