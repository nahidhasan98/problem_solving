#include<stdio.h>

#define ll long long int

int main()
{
    int test;
    scanf("%d",&test);

    for(int t=1; t<=test; t++)
    {
        ll a,b,k,temp;
        scanf("%lld%lld%lld",&a,&b,&k);

        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }

        ll need=b-a,mod=need%k;

        if(mod!=0)
            printf("-1\n");
        else
            printf("%lld\n",need/k);
    }

    return 0;
}
