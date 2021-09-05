#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,t=1;

    while(cin>>n)
    {
        if(n==0)
            break;

        if(n<=10)
            cout<<"Case "<<t<<": Impossible"<<endl;
        else
        {
            if(n%10==0)
                n-=10;

            n/=10;

            long long res=n*8;
            cout<<"Case "<<t<<": "<<res<<endl;
        }

        t++;
    }

    return 0;
}
