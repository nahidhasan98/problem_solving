#include<bits/stdc++.h>
using namespace std;

long long b,p,m;

long long solve(long long p)
{
    if(p==0)
        return 1;

    if(p%2==0)
    {
        long long temp=solve(p/2)%m;

        return ((temp%m)*(temp%m))%m;
    }
    else
        return ((b%m)*solve(p-1)%m)%m;
}
int main()
{
    while(cin>>b>>p>>m)
        cout<<solve(p)<<endl;

    return 0;
}
