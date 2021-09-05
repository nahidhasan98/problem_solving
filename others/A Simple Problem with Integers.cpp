#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct st
{
    long long left,right,val;
};

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);

    long long a[100005],sum[100005],pre=0;

    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);

        sum[i]=pre+a[i];
        pre=sum[i];
    }

    char c;
    long long x,y,z;
    vector<st>v;
    st temp;

    for(int i=1;i<=q;i++)
    {
        scanf(" %c",&c);

        if(c=='C')
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            temp.left=x;
            temp.right=y;
            temp.val=z;

            v.push_back(temp);
        }
        else
        {
            scanf("%lld%lld",&x,&y);

            long long res=0;

            if(x==1)
                res+=sum[y-1];
            else
                res+=sum[y-1]-sum[x-2];

            for(int j=0;j<v.size();j++)
            {
                int l,r;

                if(v[j].left<=x)
                    l=x;
                else if(v[j].left>x)
                    l=v[j].left;

                if(v[j].right>=x)
                    r=y;
                else if(v[j].right<x)
                    r=v[j].right;

                long long times=r-l+1;

                res+=times*v[j].val;
            }

            printf("%lld\n",res);
        }
    }

    return 0;
}
