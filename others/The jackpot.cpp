#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int n;

    while(cin>>n)
    {
        if(n==0)
            break;

        int a[n],flag=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            if(a[i]>0)
                flag=1;
        }

        for(int i=1;i<n;i++)
            a[i]+=a[i-1];

        int res=0,sum=0;

        for(int i=0;i<n;i++)
        {
            for(int j=1;(i+j-1)<n;j++)
            {
                if(i==0)
                    sum=a[i+j-1];
                else
                    sum=a[i+j-1]-a[i-1];

                res=max(res,sum);
            }
        }

        if(flag==0)
            cout<<"Losing streak."<<endl;
        else
            cout<<"The maximum winning streak is "<<res<<"."<<endl;
    }

    return 0;
}
