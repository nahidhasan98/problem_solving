#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;

    for(int t=1;t<=test;t++)
    {
        long long n;
        cin>>n;

        long long res=n*(n-1)*(n-2)*(n-3);
        res/=24;

        cout<<"Case "<<t<<": "<<res<<endl;
    }

    return 0;
}
