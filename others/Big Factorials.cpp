#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;

    while(cin>>n)
    {
        long long sum=1;

        for(long long i=2;i<=n;i++)
        {
            sum*=i;

            sum%=10000;
        }
        if(n>20)
            cout<<"0000"<<endl;
        else
            cout<<sum<<endl;
    }

    return 0;
}
