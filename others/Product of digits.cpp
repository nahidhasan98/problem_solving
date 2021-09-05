#include<bits/stdc++.h>
using namespace std;

int a[10000010];

void solve()
{
    for(int i=1; i<=1e7; i++)
    {
        int temp=i,sum=1;

        while(temp!=0)
        {
            sum*=(temp%10);
            temp/=10;
        }
        a[i]=sum;
    }
}

int main()
{
    solve();

    int test;
    cin>>test;

    for(int t=1; t<=test; t++)
    {
        int n;
        cin>>n;

        for(int i=)

        cout<<"Case "<<t<<": "<<<<endl;
    }

    return 0;
}
