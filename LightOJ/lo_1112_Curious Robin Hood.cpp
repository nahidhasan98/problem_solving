#include<bits/stdc++.h>
using namespace std;

int a[100100];

void update(int pos,int val,int m)
{
    while(pos<=m)
    {
        a[pos]=a[pos]+val;
        pos=pos+(pos&(-pos));
    }
}
int total(int x)
{
    int sum=0;

    while(x>0)
    {
        sum=sum+a[x];
        x=x-(x&(-x));
    }

    return sum;
}

int main()
{
    int t,n,q,query,loc,v,low,high,s,z;

    scanf("%d",&t);

    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);

        scanf("%d%d",&n,&q);

        memset(a,0,sizeof(a));

        for(int j=1;j<=n;j++)
        {
            scanf("%d",&s);

            update(j,s,n);
        }
        for(int k=1;k<=q;k++)
        {
            scanf("%d",&query);

            if(query==1)
            {
                scanf("%d",&z);

                int res = total(z+1) - total(z);
                printf("%d\n",res);

                update(z+1,-res,n);
            }
            else if(query==2)
            {
                scanf("%d%d",&loc,&v);

                update(loc+1,v,n);
            }
            else if(query==3)
            {
                scanf("%d%d",&low,&high);

                printf("%d\n",total(high+1)-total(low-1+1));
            }
        }
    }

    return 0;
}
