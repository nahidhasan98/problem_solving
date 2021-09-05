#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n,k,b;
        cin>>n>>k>>b;

        int a[n+1];

        for(int i=1; i<=n; i++)
            cin>>a[i];

        int sum=0;

        if(k==1)
        {
            for(int i=1; i<=n; i++)
            {
                if(a[i]==b)
                    sum++;
            }
        }
        else if(k==2)
        {
            for(int i=1; i<=n-1; i++)
            {
                for(int j=i+1; j<=n; j++)
                {
                    if(a[i]+a[j]==b)
                        sum++;
                }
            }
        }
        else if(k==3)
        {
            for(int i=1; i<=n-2; i++)
            {
                for(int j=i+1; j<=n-1; j++)
                {
                    for(int k=j+1; k<=n; k++)
                    {
                        if(a[i]+a[j]+a[k]==b)
                            sum++;
                    }
                }
            }
        }
        cout<<"Case "<<t<<": "<<sum<<endl;
    }

    return 0;
}
