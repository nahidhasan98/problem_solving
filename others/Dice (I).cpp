#include<bits/stdc++.h>
using namespace std;

int n,k,s,mod=100000007;
int memory[1010][15010];

int solve(int n,int s)
{
    if(n==0 && s==0)
        return 1;
    if(n==0)
        return 0;
    if(s==0)
        return 0;

    if(memory[n][s]!=-1)
        return memory[n][s];

    int x=0,y=0;

    for(int i=1;i<=k;i++)
    {
        if(i<=s)
            x+=solve(n-1,s-i)%mod;
    }
    return memory[n][s]=x%mod;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>n>>k>>s;

        cout<<"Case "<<t<<": "<<solve(n,s)<<endl;
    }

    return 0;
}
