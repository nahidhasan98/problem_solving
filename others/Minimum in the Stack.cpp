#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while(cin>>n)
    {
        long long a,b,c,x0,mod=1000000;
        cin>>a>>b>>c>>x0;

        stack<long long>s;
        long long res=1000000000;

        for(int i=1;i<=n;i++)
        {
            long long x=((((a*x0*x0)%mod)+((b*x0)%mod)+c)/100)%mod;

            if(x%5<2)
            {
                e
            }
            else
            {
                s.push(x);
            }
            x0=x;
        }
    }

    return 0;
}
