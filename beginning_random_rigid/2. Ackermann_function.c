#include<stdio.h>
int acker(int m, int n);
int m,n,res;
int main()
{
    scanf("%d%d",&m,&n);

    res=acker(m,n);
    printf("\n%d\n",res);

    return 0;
}
int acker(int m, int n)
{
    if(m==0)
        res=n+1;
    else if(m!=0 && n==0)
        res=acker(m-1,1);
    else if(m!=0 && n!=0)
        res=acker(m-1,acker(m,n-1));

    return res;
}
