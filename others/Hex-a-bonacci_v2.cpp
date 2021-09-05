#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f,n;
long long memory[10010];

long long solve(int n)
{
    if(n==0)
        return a;
    if(n==1)
        return b;
    if(n==2)
        return c;
    if(n==3)
        return d;
    if(n==4)
        return e;
    if(n==5)
        return f;

    if(memory[n]!=-1)
        return memory[n];

    return memory[n]=(solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4)+solve(n-5)+solve(n-6))%10000007;
}

int main()
{
    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        memset(memory,-1,sizeof(memory));

        cin>>a>>b>>c>>d>>e>>f>>n;

        cout<<"Case "<<t<<": "<<solve(n)%10000007<<endl;
    }

    return 0;
}
