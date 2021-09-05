#include<bits/stdc++.h>
using namespace std;

void check(int z);

int main()
{
    int T,t,n,k,i,j,a[10010],flag,x,b[10010],sum;

    cin>>T;

    for(t=1;t<=T;t++)
    {
        cin>>n>>k;
        x=0;
        sum=0;

        for(i=0;i<n;i++)
            b[i]=0;

        for(i=0;i<n;i++)
        {
            cin>>a[i];
            flag=0;

            if(a[i]!=1)
            {
                for(j=2;j<=sqrt(a[i]);j++)
                {
                    if(a[i]%j==0)
                        flag=1;
                }

                if(flag!=1)
                {
                    b[x]=a[i];
                    x++;
                }
            }
        }

        for(i=k-1;b[i]!=0;i=i+k)
            sum=sum+b[i];

        cout<<sum<<endl;
    }

    return 0;
}
