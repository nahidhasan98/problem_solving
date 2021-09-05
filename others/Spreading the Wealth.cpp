#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

long long absolute(long long n)
{
    if(n<0)
        return n*(-1);
    else
        return n;
}

int main()
{
    //FI FO

    int n;

    while(cin>>n)
    {
        long long a[n],need[n],total=0,tr[n],sum[n],result=0;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            total+=a[i];
        }

        for(int i=0; i<n; i++)
            need[i]=(total/n)-a[i];

        sum[n-1]=need[n-1];
        for(int i=n-2; i>=0; i--)
            sum[i]=need[i]+sum[i+1];

        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }

        sort(sum,sum+n);

        if(n%2==0)
        {
            long long num1=sum[n/2];
            long long num2=sum[(n/2)-1];

            tr[0]=(num1+num2)/2;
        }
        else
            tr[0]=sum[(n/2)+1];

        result+=absolute(sum[0]-tr[0]);
        for(int i=1; i<n; i++)
        {
            tr[i]=sum[i]-tr[0];
            result+=absolute(tr[i]);
        }
        cout<<result<<endl;
    }

    return 0;
}
/*
2
7 5
*/
