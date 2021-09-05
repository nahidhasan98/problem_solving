#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[110];
int memory[10010][110];

int solve(int k,int pos)
{
    if(k==0)
        return 1;
    if(k<0 || pos>n)
        return 0;

    if(memory[k][pos]!=-1)
        return memory[k][pos];

    int x=0;

    for(int i=0;i<=k;i++)
        x+=solve(k-(a[pos]*i),pos+1)%100000007;

    return memory[k][pos]=x;
}

int main()
{
    int t;
    cin>>t;

    for(int T=1;T<=t;T++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>n>>k;

        for(int i=1;i<=n;i++)
            cin>>a[i];

        cout<<"Case "<<T<<": "<<solve(k,1)<<endl;
    }

    return 0;
}
