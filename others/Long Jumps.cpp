#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

#define FI freopen("in.txt","r",stdin);
#define FO freopen("out.txt","w",stdout);

int a[200000+5],memory[200000+5];

int dp(int idx,int n)
{
    if (idx>n)
        return 0;
    if(memory[idx]!=-1)
        return memory[idx];

    int next=idx+a[idx];

    return memory[idx]=a[idx]+dp(next,n);
}

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        memset(a,0,sizeof(a));
        memset(memory,-1,sizeof(memory));

        int n;
        cin>>n;

        for(int i=1; i<=n; i++)
            cin>>a[i];

        int sum=0;
        for(int i=1; i<=n; i++)
            sum=max(sum,dp(i,n));

        cout<<sum<<endl;
    }

    return 0;
}
